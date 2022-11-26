# R2A

> Raylib -> Ascede translator

R2A is a tiny tool that I would like to use to translate *Raylib* into *Ascede*. It is intended merely for personal use, and I will thus be really careless about the project.

To build, just compile `r2a.c`. The other `.c` source files aren't actual code. I gave them the `.c` extension so that I would be able to edit them more easily in my Code::Blocks IDE.

Its capabilities include:

- [x] Deleting files
- [x] Removing functions from files
  - Needs updating from version to version
- [x] Rearranging API (by replacing syntaxes)
  - Needs updating from version to version
- [ ] Adjusting (e.g. deleting certain lines from) certain functions
  - Scheduled functions to adjust:
    - `EndDrawing()`
    - `WindowShouldClose()`
- [ ] Adding files, injecting functions, etc.
  - Scheduled functions to inject:
    - `ASC_ALLOC()`
    - `ASC_REALLOC()`
    - `ASC_FREE()`
    - `ASC_FREEALL`
    - `RNG_SetSeed()`
    - `RNG_SetState()`
    - `RNG_Gen()`
    - `RNG_GenDouble()`
    - `Time_Sleep()`
    - `Time_Get()`
    - `Time_GetFPS()`
    - `Time_GetRealFPS()`
    - `Time_Wait()`
    - `Texture_DrawCentered()`
  - Other changes in plan (but are less likely to implement):
    - Better text rendering
    - Rewrite audio module
    - 2D instancing
- [ ] [Optional] Generating cheat sheets and find out API changes in *Raylib*
  - This, if implemented, will add great convenience to the edit of deletion and rearrangement lists.