#include "GameLoop.h"
#include "DataContainer.h"

int main()
{
    Game::GameLoop gameLoop;
    Data::DataContainer theWholeData;
    
    gameLoop.ReceiveData(theWholeData);
    
    gameLoop.Run();
    
    return 0;
}
