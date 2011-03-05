/* on database connection */
PRAGMA foreignkey = ON
/* create new db file */
CREATE TABLE 'inv'.'tags' ('id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE , 'name' VARCHAR(20) NOT NULL )
CREATE TABLE 'inv'.'status' ('id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE , 'name' VARCHAR(50) NOT NULL UNIQUE , 'bgcolor' VARCHAR(6) NOT NULL DEFAULT ffffff, 'fgcolor' VARCHAR(6) NOT NULL DEFAULT 000000)
CREATE TABLE 'inv'.'addresses' ('id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE , 'name' VARCHAR(50) NOT NULL UNIQUE , 'country' VARCHAR(25), 'town' VARCHAR(50), 'postal_code' VARCHAR(10), 'street' TEXT check(typeof('street') = 'text') , 'ref' VARCHAR(5) NOT NULL )
CREATE TABLE 'inv'.'information' ('id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE , 'name' varchar(10) NOT NULL UNIQUE , 'data' TEXT NOT NULL check(typeof('data') = 'text') )
CREATE TABLE 'inv'.'locations' ('id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE , 'ref' VARCHAR(10) NOT NULL UNIQUE , 'name' VARCHAR(20) NOT NULL UNIQUE , 'creationdate' DATETIME NOT NULL , 'closingdate' DATETIME NOT NULL , 'accessdate' DATETIME NOT NULL DEFAULT CURRENT_DATE, 'description' TEXT NOT NULL , address_id INTEGER NOT NULL, FOREIGN KEY(address_id) REFERENCES addresses(id))
CREATE TABLE 'inv'.'items' ('id' INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE , 'ref' VARCHAR(20) NOT NULL UNIQUE , 'name' VARCHAR(50) NOT NULL UNIQUE , 'entrydate' DATETIME NOT NULL , 'recorddate' DATETIME NOT NULL , 'description' TEXT NOT NULL , 'accessdate' DATETIME NOT NULL DEFAULT CURRENT_DATE, 'qrcode' BLOB, 'location' INTEGER NOT NULL, FOREIGN KEY(location) REFERENCES locations(id) )
INSERT INTO 'status' VALUES ('','valid','','00aa00'); INSERT INTO 'status' VALUES ('','Destroyed','','777777'); INSERT INTO 'status' VALUES ('','Lost','ff0000','000000');
INSERT INTO 'information' VALUES ('','program_version','0.1'); INSERT INTO 'information' VALUES ('','latest_access_date','date("now")'); INSERT INTO 'information' VALUES ('','latest_modification_date','date("now")'); 
