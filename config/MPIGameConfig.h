/* 
 * File:   MPIGameConfig.h
 * Author: skrep
 *
 * Created on 3 de Março de 2015, 19:08
 */

#ifndef MPIGAMECONFIG_H
#define	MPIGAMECONFIG_H

class MPIGameConfig {
public:
    MPIGameConfig();
    MPIGameConfig(const MPIGameConfig& orig);
    virtual ~MPIGameConfig();
    
    const static int BATTLEFIELD_SIZE_X    = 50;
    const static int BATTLEFIELD_SIZE_Y    = 50;
    const static int NPC_COUNT             = 100000;
    const static int RANDOM_WAIT_TIME_MS   = 1000;
    const static long MIN_LOOP_TIME_NS     = 20000000;
    const static int SYSTEM_RUNTIME_MS     = 30000;
    
    /* Measured in Degrees per second */
    const static int SLOW_TURN_SPEED       = 180;
    const static int FAST_TURN_SPEED       = 360;
    /* Measured in Meters per second */
    const static double WALK_SPEED         = 1.5;
    const static double RUN_SPEED          = 5.0;
private:

};

#endif	/* MPIGAMECONFIG_H */
