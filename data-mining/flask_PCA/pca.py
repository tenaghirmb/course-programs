# -*- coding: utf-8 -*-
# @Author: aka
# @Date:   2018-07-07 12:02:47
# @Last Modified by:   aka
# @Last Modified time: 2018-07-08 23:00:07
# @Email: tenag_hirmb@hotmail.com

from flask import Flask, jsonify
from flask import request
from sklearn.decomposition import PCA

app = Flask(__name__)


def pca_proc(data, n):
    return PCA(n_components=n).fit_transform(data)


@app.route("/pca", methods=['POST'])
def pca():
    data = request.get_json(force=True)
    # parameter - n_components
    n = int(request.args.get('n', len(data[0])))
    result = pca_proc(data, n).tolist()
    return jsonify(result)
