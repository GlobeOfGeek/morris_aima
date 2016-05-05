#include <VacuumEnvironment.h>
#include <TileFrameVisualizer.h>
#include <Simulator.h>
#include "SimulatorFactory.h"

#define DEFAULT_CYCLE_TIME 1000
Simulator *SimulatorFactory::createSimulator(std::string type, std::string name, std::string mapFile, long cycleTime) {
    Simulator *created;
    Environment *environment;
    Visualizer *visualizer;

    if(type.compare("VacuumWorld")==0) {
        environment = new VacuumEnvironment;
        environment->loadEnvironment(mapFile);
        visualizer = new TileFrameVisualizer(2,1, name);
        created = new Simulator(environment, visualizer, cycleTime);
    } else {
        created = NULL;
    }
    return created;
}

