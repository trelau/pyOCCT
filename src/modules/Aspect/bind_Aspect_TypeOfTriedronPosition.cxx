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
#include <Aspect_TypeOfTriedronPosition.hxx>

void bind_Aspect_TypeOfTriedronPosition(py::module &mod){

py::enum_<Aspect_TypeOfTriedronPosition>(mod, "Aspect_TypeOfTriedronPosition", "Definition of the Trihedron position in the views. It is defined as a bitmask to simplify handling vertical and horizontal alignment independently.")
	.value("Aspect_TOTP_CENTER", Aspect_TypeOfTriedronPosition::Aspect_TOTP_CENTER)
	.value("Aspect_TOTP_TOP", Aspect_TypeOfTriedronPosition::Aspect_TOTP_TOP)
	.value("Aspect_TOTP_BOTTOM", Aspect_TypeOfTriedronPosition::Aspect_TOTP_BOTTOM)
	.value("Aspect_TOTP_LEFT", Aspect_TypeOfTriedronPosition::Aspect_TOTP_LEFT)
	.value("Aspect_TOTP_RIGHT", Aspect_TypeOfTriedronPosition::Aspect_TOTP_RIGHT)
	.value("Aspect_TOTP_LEFT_LOWER", Aspect_TypeOfTriedronPosition::Aspect_TOTP_LEFT_LOWER)
	.value("Aspect_TOTP_LEFT_UPPER", Aspect_TypeOfTriedronPosition::Aspect_TOTP_LEFT_UPPER)
	.value("Aspect_TOTP_RIGHT_LOWER", Aspect_TypeOfTriedronPosition::Aspect_TOTP_RIGHT_LOWER)
	.value("Aspect_TOTP_RIGHT_UPPER", Aspect_TypeOfTriedronPosition::Aspect_TOTP_RIGHT_UPPER)
	.export_values();


}