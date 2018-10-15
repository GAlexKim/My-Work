from PIL import Image

def image_resize(image_path, width):
    img = Image.open(image_path)
    img = img.resize((width, width), Image.ANTIALIAS)
    img.save('convert_image.jpg')
    img.show()
    
if __name__=='__main__':
    print('Image Resizing Application')
    print(r"Example: C:\Users\geonw\Desktop\New folder\image1.jpg")
    path = input('Enter the full path of the image according to the example above: ')
    width = input('Enter the desired width of your image: ')
    width = int(width)
    image_resize(path, width)
