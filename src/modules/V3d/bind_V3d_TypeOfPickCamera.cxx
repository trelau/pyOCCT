/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <V3d_TypeOfPickCamera.hxx>

void bind_V3d_TypeOfPickCamera(py::module &mod){

py::enum_<V3d_TypeOfPickCamera>(mod, "V3d_TypeOfPickCamera", "None")
	.value("V3d_POSITIONCAMERA", V3d_TypeOfPickCamera::V3d_POSITIONCAMERA)
	.value("V3d_SPACECAMERA", V3d_TypeOfPickCamera::V3d_SPACECAMERA)
	.value("V3d_RADIUSTEXTCAMERA", V3d_TypeOfPickCamera::V3d_RADIUSTEXTCAMERA)
	.value("V3d_ExtRADIUSCAMERA", V3d_TypeOfPickCamera::V3d_ExtRADIUSCAMERA)
	.value("V3d_IntRADIUSCAMERA", V3d_TypeOfPickCamera::V3d_IntRADIUSCAMERA)
	.value("V3d_NOTHINGCAMERA", V3d_TypeOfPickCamera::V3d_NOTHINGCAMERA)
	.export_values();


}