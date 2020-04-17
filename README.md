# About

This program simulates how the RNG function in the game Zelda: Twilight Princess works. It uses three int32 values to function as a seed, and returns a normalized floating point value as the final RNG value to be consumed by whatever function called it (so every call to the function changes the seed).