#include "CopyProcessor.h"
#include <assert.h>

// ������ �� ������, � ����� �� �������� ��������� read � write
const size_t CopyProcessor::buffer_size = 1024;

CopyProcessor::CopyProcessor(InputStream * input, OutputStream * output) :
                             input(input), output(output)
{
    assert(input);
    assert(output);
}

void CopyProcessor::Process()
{
    unsigned char buffer[buffer_size];
    int size;

    // ������������� �� �������� � �������� ��
    if(input->CanSeek())  input->Seek(0);
    if(output->CanSeek()) output->Seek(0);

    while(size=input->Read(buffer, buffer_size))
    {
        output->Write(buffer, size);
    }
    output->Flush();
}
