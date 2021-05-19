//Just some stuff I yoinked from stackoverflow for now


// Maybe we can do some simple spectrum pattern recognition to see what emotions the inflowing audio is supposed to have. e.g. margin maps to compare a few windows to.
// It would be ideal if we can get the entire audio output file before it is played, instead of a stream so that it can be processed this way, 
// as such a method would be much more accurate than operating on a stream

// Obviously no existant voice assistant outputs audio with any emotion currently, but hey it will probably happen in the near future.

Uint8* sampData;
SDL_AudioSpec wavSpec;
Uint8* wavStart;
Uint32 wavLength;
SDL_AudioDeviceID aDevice;

struct AudioData {
    Uint8* filePosition;
    Uint32 fileLength;
};

void PlayAudioCallback(void* userData, Uint8* stream, int streamLength) {
    AudioData* audio = (AudioData*)userData;
    sampData = new Uint8;

    if (audio->fileLength == 0) {
        return;
    }

    Uint32 length = (Uint32)streamLength;
    length = (length > audio->fileLength ? audio->fileLength : length);

    SDL_memcpy(stream, audio->filePosition, length);

    // HERE is where i'd like to implement the FFT on 'stream' data 
    // but i don't know how to implement this using FFTW

    audio->filePosition += length;
    audio->fileLength -= length;
}