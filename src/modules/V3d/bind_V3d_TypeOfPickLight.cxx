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
#include <V3d_TypeOfPickLight.hxx>

void bind_V3d_TypeOfPickLight(py::module &mod){

py::enum_<V3d_TypeOfPickLight>(mod, "V3d_TypeOfPickLight", "None")
	.value("V3d_POSITIONLIGHT", V3d_TypeOfPickLight::V3d_POSITIONLIGHT)
	.value("V3d_SPACELIGHT", V3d_TypeOfPickLight::V3d_SPACELIGHT)
	.value("V3d_RADIUSTEXTLIGHT", V3d_TypeOfPickLight::V3d_RADIUSTEXTLIGHT)
	.value("V3d_ExtRADIUSLIGHT", V3d_TypeOfPickLight::V3d_ExtRADIUSLIGHT)
	.value("V3d_IntRADIUSLIGHT", V3d_TypeOfPickLight::V3d_IntRADIUSLIGHT)
	.value("V3d_NOTHING", V3d_TypeOfPickLight::V3d_NOTHING)
	.export_values();


}