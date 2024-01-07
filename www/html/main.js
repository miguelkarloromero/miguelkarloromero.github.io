function checkDevice() {
	const regex = /Mobi|Android|webOS|iPhone|iPad|iPod|BlackBerry|IEMobile|Opera Mini/i;
	return regex.test(navigator.userAgent);
}
if (checkDevice()) {
	document.getElementById("device_type").innerHTML = "Your Are Using a Mobile Browser";
}
else {
	document.getElementById("device_type").innerHTML = "You Are Using a Desktop Browser";                                             }
