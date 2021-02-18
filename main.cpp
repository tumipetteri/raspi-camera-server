#include "serverapp.h"

int main(int argc, char *argv[])
{
    ServerApp app(argc, argv);

    return app.exec();
}
