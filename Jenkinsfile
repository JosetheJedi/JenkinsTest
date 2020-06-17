pipeline 
{
    agent any
    stages 
    {
        stage("Build")
        {
            steps{
                sh '''
                ls 
                ls -lah

                '''
                cmakeBuild buildDir: 'build', buildType: 'Debug', cleanBuild: true, generator: 'Unix Makefiles', installation: 'InSearchPath', sourceDir: './'

                sh '''
                ls 
                ls build
                cd build 
                make
                '''
            }
        }
        stage("Run Google Test")
        {
            steps{
                sh '''
                    echo "Starting google test"
                    cd test
                    ./UnitTests --gtest_output="xml:testresults.xml"
                '''
            }
        }
    }
    post 
    {
        always {
            archiveArtifacts 'build/test/testresults.xml'
            cleanWs()
        }
        failure {
            archiveArtifacts 'build/test/testresults.xml'
        }
    }
}