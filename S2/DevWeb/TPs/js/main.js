function resizeIFrameToFitContent(iFrame) {
    if (iFrame.contentWindow)
        iFrame.height = iFrame.contentWindow.document.body.scrollHeight + 50 + "px";
}
