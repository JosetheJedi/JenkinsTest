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

                    ar -rv gtest_main.a gtest_main.o gtest-all.o
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