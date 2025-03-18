#include <stdio.h>
#include <stdlib.h>
#include "chip_agent.h"

#if defined(CHIP_A)
#include "chip_a.h"
typedef struct dragonwing_NPA7 chip_impl_t;
#define CHIP_INIT(ptr) dragonwing_NPA7_init(ptr)
#define CHIP_SHUTDOWN(ptr) dragonwing_NPA7_shutdown(ptr)
#define CHIP_START(ptr)                        \
    do                                         \
    {                                          \
        printf("dragonwing_NPA7 network module starts\n");\
        dragonwing_NPA7_set_register1(ptr, 1); \
        dragonwing_NPA7_set_register2(ptr, 1); \
    } while (0)
#define CHIP_STOP(ptr)                         \
    do                                         \
    {                                          \
        dragonwing_NPA7_set_register1(ptr, 0); \
        dragonwing_NPA7_set_register2(ptr, 0); \
    } while (0)

#elif defined(CHIP_B)
#include "chip_b.h"
typedef struct link_street chip_impl_t;
#define CHIP_INIT(ptr) link_street_init(ptr)
#define CHIP_SHUTDOWN(ptr) link_street_shutdown(ptr)
#define CHIP_START(ptr)                    \
    do                                     \
    {                                      \
        printf("MARVELL_LINKSTREET network module starts\n");\
        link_street_set_registerA(ptr, 1); \
        link_street_set_registerB(ptr, 1); \
    } while (0)
#define CHIP_STOP(ptr)                     \
    do                                     \
    {                                      \
        link_street_set_registerA(ptr, 0); \
        link_street_set_registerB(ptr, 0); \
    } while (0)

#elif defined(CHIP_C)
#include "chip_c.h"
typedef struct snapdragon chip_impl_t;
#define CHIP_INIT(ptr) snapdragon_init(ptr)
#define CHIP_SHUTDOWN(ptr) snapdragon_shutdown(ptr)
#define CHIP_START(ptr)                    \
    do                                     \
    {                                      \
        printf("QUALCOMM_SNAPDRAGON network module starts\n");\
        snapdragon_set_registerI(ptr, 1);  \
        snapdragon_set_registerII(ptr, 1); \
    } while (0)
#define CHIP_STOP(ptr)                     \
    do                                     \
    {                                      \
        snapdragon_set_registerI(ptr, 0);  \
        snapdragon_set_registerII(ptr, 0); \
    } while (0)

#else
#error "No chip defined!  Please define CHIP_A, CHIP_B, or CHIP_C during compilation."
#endif

struct chip_agent
{
    chip_impl_t chip_impl;
};

struct chip_agent *agent_create(void)
{
    struct chip_agent *agent = malloc(sizeof(struct chip_agent));
    if (agent == NULL)
    {
        return NULL;
    }

    return agent;
}

void agent_set(struct chip_agent *agent)
{
    if (agent == NULL)
    {
        return;
    }
    CHIP_INIT(&agent->chip_impl);
    CHIP_START(&agent->chip_impl);
}

void agent_destroy(struct chip_agent *agent)
{
    if (agent == NULL)
    {
        return;   
    }
    
    CHIP_STOP(&agent->chip_impl);
    CHIP_SHUTDOWN(&agent->chip_impl);
    free(agent);
}

void agent_run_network(struct chip_agent *agent)
{
    agent = agent; // suppress compiler warning
    // implementation
    return;
}