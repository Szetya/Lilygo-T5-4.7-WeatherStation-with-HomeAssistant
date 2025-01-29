# imgconvert

## 1. Prerequisites

Before using the script, ensure that you have the required dependencies installed. You need Python 3 and the Pillow library.

```shell
python3 -m pip install pillow
```

## 2. Instructions

To run the script, use the following command:

```shell
python imgconvert.py [-h] [-i INPUTFILE] [-n NAME] [-o OUTPUTFILE]
```

- `-i INPUTFILE`: Specifies the input image file.
- `-n NAME`: Sets the variable name for the generated header file.
- `-o OUTPUTFILE`: Specifies the output header file (.h file).

## 3. Using for Weather Display

The script is designed to process an image (such as a map) for display on an embedded screen. It ensures that the image is resized proportionally to fit the display while maintaining its aspect ratio.

Example usage:

```shell
python imgconvert.py -i mapfile.png -n mapTile -o map.h
```

## 4. Display Coordinate Mapping

Once the `map.h` file is generated, you need to define the geographical coordinates that correspond to the displayed area on the screen. This allows proper positioning of map elements such as city markers.

Example coordinate definitions:

```cpp
const float mapTileLonMin = 15.5500;  // Minimum longitude (left edge of the display)
const float mapTileLonMax = 23.3500;  // Maximum longitude (right edge of the display)
const float mapTileLatMin = 45.7000;  // Minimum latitude (bottom edge of the display)
const float mapTileLatMax = 48.6000;  // Maximum latitude (top edge of the display)
```

## 5. Obtaining a Suitable Map Image

To generate a suitable map for your display, you can obtain a base image using the following methods:

- **Online map generators**: Many websites provide blank or styled maps, such as:
  - [OpenStreetMap Export](https://www.openstreetmap.org/export)
  - [Stamen Maps](http://maps.stamen.com/)
  - [Carto](https://carto.com/)
- **Screenshots from mapping services**: Take a screenshot from Google Maps, OpenStreetMap, or other GIS tools.
- **Custom-generated maps**: You can create a custom map using software like QGIS or Photoshop, ensuring it matches your display size.

## 6. Final Steps

After generating the `map.h` file, copy it to the `src` directory of your project:

```shell
cp map.h src/
```

This ensures the file is available for your embedded system’s build process.

---

With these steps, you can successfully convert a map image for your display and overlay weather data on it.

