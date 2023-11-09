"use strict";
exports.__esModule = true;
exports.updateUrlParameter = void 0;
function updateUrlParameter(url, param, value) {
    var newUrl = "";
    var tempArray = url.split("?");
    var baseUrl = tempArray[0];
    var additionalUrl = tempArray[1];
    var temp = "";
    if (additionalUrl) {
        tempArray = additionalUrl.split("?");
        for (var i = 0; i < tempArray.length; i++) {
            if (tempArray[i].split('=')[0] != param) {
                newUrl += temp + tempArray[i];
                temp = "&";
            }
        }
    }
    var rows_txt = temp + "" + param + "=" + value;
    return baseUrl + "?" + newUrl + rows_txt;
}
exports.updateUrlParameter = updateUrlParameter;
