# 3D-Indoor-localization-system
The project uses audio signals to locate objects in the 3D space. 

The system subsists of 3 or more beacons at known positions and a mobile station. To
determine the position of the mobile station the mobile station calculates its distance from each
of the beacons, with this information in addition to the knowledge of the positions of the
beacons the mobile station is able to calculate its position by a procedure called trilateration.
To determine the distance of the mobile station from a beacon the beacon releases at
the same time both an FM signal and an audio signal. The FM signal travelling at the speed of
light arrives instantaneously while the audio signal travelling at a much slower speed takes a
measurable amount of time. By calculating the delay between the arrival of the FM signal and
the audio signal at the base station the mobile station is able to calculate its distance from the
beacon.
