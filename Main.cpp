#include "Tests/ParticleTest.h"
#include "Tests/ForceTest.h"
#include "Tests/JointTest.h"

int main(int argc, char* args[])
{
    Test* test = new JointTest();

    test->Initialize();
    while (!test->IsQuit()) test->Run();
    delete test;

    return 0;
}