#include "TextBinder.h"
#include <assert.h>
#include <ctype.h> //isspace

TextBinder::TextBinder(InputStream * stream1, InputStream * stream2) :
                       position(0), activeStream(0)
{
    assert(stream1);
    assert(stream2);
    first[0] = first[1] = 0;
    streams[0] = stream1;
    streams[1] = stream2;
    streams[0]->Seek(0);
}

int TextBinder::GetPosition()
{
    return position;
}

int TextBinder::GetLength()
{
    return -1;
}

void TextBinder::Seek(int position)
{
}

int TextBinder::Read(unsigned char * buffer, int size)
{
    assert(buffer);
    const static unsigned char space = ' '; // ����������
    unsigned char ch;
    static bool one_stream = false;
    for(int i = 0; i < size; ++i)
    {
        // ��� ��� �������� ������, �������� ��
        if(first[activeStream])
        {
            ch = first[activeStream];
            first[activeStream] = 0;
        }
        else
        {
            if(!streams[activeStream]->Read(&ch, 1))
            { 
                // ��� ������� ����� � �������
                activeStream = 1-activeStream;
                if(one_stream)  // � ����� �� ��������
                { 
                    position += i;
                    return i;
                }
                else 
                { 
                    one_stream = true; 
                    --i;  // ������ ������������� �� i � ������
                    continue;
                }
            }
        }
        if(isspace(ch))  // ��� � ��������
        { 
            buffer[i] = space;
            int res;
            // ��������� �� �������� �������
            while(isspace(ch) && (res = streams[activeStream]->Read(&ch, 1)))
                ;
            first[activeStream] = res ? ch : 0;
            // ��� ��� ����� � ������ �����, ������ �� ��������
            if(!one_stream)
            {
                activeStream = 1 - activeStream;
            }
        }
        else
        { 
            buffer[i] = ch;
        }
    }
    position += size;
    return size;
}

int TextBinder::CanGetPosition()
{
    return true;
}

int TextBinder::CanGetLength()
{
    return false;
}

int TextBinder::CanSeek()
{
    return false;
}
