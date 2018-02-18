# Market Modeler
Market Modeler analyzes historical price data (daily) for a list of stocks or other tradable financial assests. The Market Modeler will output common technical indicators that can be used to determine potential entry and/or exit points to certain stocks. 

## Installing
1.) Download the files to your computer or fork the repository.
2.) Open your terminal or preferred shell program and navigate to the directory containing Market Modeler's source files.
3.) Compile Market Modeler on your machine by typing the **make** command in Market Modeler's root directory.

 - **c:\market-modeler> make**

The program is now ready for use.

## Usage
Pricing data is contained in text files that are stored in the folder named "data." The text files contain daily price data and have the following data fields in this order: 

 *Date, Opening Price, Daily Price High, Daily Price Low, Closing Price, Yesterday's Closing Price, Today's Trading Volume*

There are two options for loading data into the modeler. 

1.) Include all the data files on the command line with the program.

- **c:\market-modeler> ./investor data/companyA.txt data/companyB.txt data/companyC.txt**

2.) Run the modeler by itself and modeler will repeatedly prompt the user to enter file names separately. 

- **c:\market-modeler> ./investor**

If loading via the second option, use the "load complete" command to tell modeler there are no more files to be loaded. After data has been loaded, Modeler prompts the user for a command:

 - **cmd 1>**

 There is a space after the angle bracket. The number in the prompt starts at 1 and increments each time the prompt is printed. There are several commands available to the user (see next section). 

## Commands






## Design

###### Components

* [Analyzer] - The analyzer class outputs statistics for a portfolio of stocks.

* [Bank] - The bank class represents a financial institution.

* [Market] - The market represents all of the stocks that currently trade.

* [Portfolio] - Portfolio is a select group of securities held by an individual trader or investment firm. The securities are stored in a vector and provide functionality for adding, removing, and sorting the list of securities. 

* [Security] - Defines the classes for different types of tradable financial assets. At the most basic level, a Security has a valuevand a market capitalization. Security is an abstract class and is the base class for Stock.

* [Stock] - A security that can be bought and sold. The stock has a name, a ticker, and a quantity of shares. The Stock can
  be bought by a trader or investment firm and the Stock can print out the issuing company.

* [Date] - A day

* [Filereader] - Reads historical price data from a text file into the modeler.

* [Location] -   Location describes a physical location in the USA with an address, description of the environment 
  (e.g. rural, urban, suburban), latitude, and longitude.

* [Stocklist] - StockList is a doubly linked list of Stocks. It provides basic functionality for constructing a list of stocks,adding, removing, and sorting stocks by price. Overloaded constructors enable a few different options for construction.The Node class contains a Stock, a pointer to the previous Node, and a pointer to the successor Node. The Node class is nested in StockList, giving StockList access to Node's members.

## Running the Tests

## Contributing

## Authors
 - Arthur Vargas - ahvargas92@gmail.com


### Development


```
#### Building for source
For production release:
```sh
$ gulp build --prod
```
Generating pre-built zip archives for distribution:
```sh
$ gulp build dist --prod
```
### Docker
Dillinger is very easy to install and deploy in a Docker container.

By default, the Docker will expose port 8080, so change this within the Dockerfile if necessary. When ready, simply use the Dockerfile to build the image.

```sh
cd dillinger
docker build -t joemccann/dillinger:${package.json.version}
```
This will create the dillinger image and pull in the necessary dependencies. Be sure to swap out `${package.json.version}` with the actual version of Dillinger.

Once done, run the Docker image and map the port to whatever you wish on your host. In this example, we simply map port 8000 of the host to port 8080 of the Docker (or whatever port was exposed in the Dockerfile):

```sh
docker run -d -p 8000:8080 --restart="always" <youruser>/dillinger:${package.json.version}
```

Verify the deployment by navigating to your server address in your preferred browser.

```sh
127.0.0.1:8000
```



### Todos

 - Develop GUI 
 - 

License
----

Public


