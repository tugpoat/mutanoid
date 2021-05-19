This is a project for a simple personality visualization for a voice assistant.

building:
you need SDL2, SDL2_mixer, SDL2_image, SDL2_gfx and maybe SDL2_ttf.

CScreen is built in mind with the intention that it may be used to display things other than faces.
For example, the assistant visualization could switch to an on-screen character and present weather data.

TODO:
Use simple volume based calculations to determine if the mouth should be moving or not.
or just when audio is playing. start small.
Maybe later there can be some fancy spectrum analysis to determine the emotions of the playing audio.
