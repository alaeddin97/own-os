
void printf(char *str) {
    unsigned short* videoMemory = (unsigned short*) 0xb8000;

    for (int i;str[i]!='\0';i++)
        videoMemory[i] = (0x0F << 8) | str[i];
}

extern "C" void kernelMain(void *multiboot_structure, unsigned int magicnumber) {
    printf("Hello world! - - - this is good");

    while(1);
}
