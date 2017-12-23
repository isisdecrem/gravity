import os, time, subprocess, pygame

path = "/Users/timoothy/Desktop/particles/f"
ext = ".pgm"

index = 1

def file_exists(path_to_file):
    return os.path.isfile(path_to_file)

p = None

pygame.init()

width = 1024
height = 768

screen = pygame.display.set_mode((width, height))
clock = pygame.time.Clock()

clock.tick(60)

while True:
    file_path = path + str(index) + ext
    if file_exists(file_path):
        if (file_exists(path + str(index + 1) + ext)):
            index += 1
            continue
        try:
            p.kill()
        except:
            pass
        print "Displaying image #%s" % index

        screen.blit(pygame.image.load(path + str(index - 1) + ext), (0, 0))
        pygame.display.flip()

        index += 1
    pygame.display.update()
    time.sleep(0.1)
