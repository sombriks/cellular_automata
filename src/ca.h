#ifndef __CA_H__
#define __CA_H__

#include "bitmap.h"
#include <stdint.h>
#include <stdio.h>

typedef struct {
	uint16_t surviveset;
	uint16_t birthset;
} ruleset_t;

typedef struct {
	uint8_t *lut;
} ruleset_lut_t;

typedef struct {
	int w;
	int h;
	bitmap_t g[2];
} world_t;

#define lut_data(LUT_, I_, J_, K_) ((LUT_)->lut[((I_)<<16) + ((J_)<<8) + (K_)])
#define world_data(WW_, GG_, XX_, YY_) ((WW_)->g[GG_].d[(YY_)*(WW_)->w + (XX_)])

ruleset_t *build_ruleset(const char *s);
void free_ruleset(ruleset_t *rs);
ruleset_lut_t *build_ruleset_lut(const ruleset_t *rs, void(*progress_reporter)(int));
void free_ruleset_lut(ruleset_lut_t *rsl);
world_t *create_world(int w, int h);
void free_world(world_t *wo);
void update_world(world_t *t, const ruleset_lut_t *rsl, int generation);
void world_set_cell(world_t *wo, int generation, int x, int y, int state);

#endif
