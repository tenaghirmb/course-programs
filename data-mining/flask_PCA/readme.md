## Run the flask application

### 1. install dependencies

`pip install -r requirements.txt`

### 2. export environment variable

`export FLASK_APP=pca.py`

### 3. use the flask command

`flask run`

## API instructions

1. HTTP method: POST
2. URL: 127.0.0.1:5000/pca
3. request parameter:  *n* (optional)
   - Name: n
   - Type: number
   - Description: n_components - Number of components to keep.
   - Default: number of the features
4. request body: JSON Array
5. response body: JSON Array
6. Example:![](https://ws3.sinaimg.cn/large/006tKfTcgy1ft2vpr5zwdj30qm19adks.jpg)