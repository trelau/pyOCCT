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
#include <Aspect_FillMethod.hxx>

void bind_Aspect_FillMethod(py::module &mod){

py::enum_<Aspect_FillMethod>(mod, "Aspect_FillMethod", "Defines the fill methods to write bitmaps in a window.")
	.value("Aspect_FM_NONE", Aspect_FillMethod::Aspect_FM_NONE)
	.value("Aspect_FM_CENTERED", Aspect_FillMethod::Aspect_FM_CENTERED)
	.value("Aspect_FM_TILED", Aspect_FillMethod::Aspect_FM_TILED)
	.value("Aspect_FM_STRETCH", Aspect_FillMethod::Aspect_FM_STRETCH)
	.export_values();


}