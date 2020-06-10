pipeline 
{
    agent any
    stages 
    {
        stage("Build")
        {
            steps{
                sh '''
                    echo "Building project"
                    ls
                    g++ -isystem ./googletest/googletest/include/ -I./googletest/googletest/ -pthread -c ./googletest/googletest/src/gtest-all.cc ./googletest/googletest/src/gtest_main.cc

                    ar -rv .googletest/googletest/gtest_main.a gtest_main.o gtest-all.o

                    echo "Building Project"

                    cd build

                    g++ -isystem ../googletest/googletest/include/ -pthread ../Example.cpp ../test/ExampleTests.cpp ../test/ExampleTests2.cpp ../googletest/googletest/gtest_main.a -o ExampleTests
                '''
            }
        }
        stage("Run Google Test")
        {
            steps{
                sh '''
                    echo "Starting google test"
                    ls
                '''
            }
        }
    }
    post 
    {
        always {
            archiveArtifacts 'testresults.xml'
            cleanWs()
        }
        failure {
            archiveArtifacts 'testresults.xml'
        }
    }
}