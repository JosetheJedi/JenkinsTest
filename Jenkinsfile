pipeline 
{
    agent any
    stages 
    {
        stage("Build")
        {
            steps{
                cmakeBuild buildDir: 'build', buildType: 'Debug', cleanBuild: true, generator: 'Unix Makefiles', installation: 'InSearchPath', sourceDir: 'src'
            }
        }
        stage("Run Google Test")
        {
            steps{
                sh '''
                    echo "Starting google test"
                    build/ExampleTests --gtest_output="xml:testresults.xml"
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
            archiveArtifacts 'build/testresults.xml'
        }
    }
}