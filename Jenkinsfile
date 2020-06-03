pipeline 
{
    agent any
    stages 
    {
        stage("Build")
        {
            steps{
                git 'file:///home/josefhu15/Desktop/JenkinsTest/'
                sh 'echo "Hello World"'
                sh '''
                    echo "Multiline shell steps works too"
                    ls -lah
                    cd build
                    ls -lah
                    cmake ..
                    make
                '''
            }
        }
        stage("Run Google Test")
        {
            steps{
                sh '''
                    echo "Starting google test"
                    ls -lah
                    build/test/UnitTests --gtest_output="xml:testresults.xml"
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