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
#include <OpenGl_LayerFilter.hxx>

void bind_OpenGl_LayerFilter(py::module &mod){

py::enum_<OpenGl_LayerFilter>(mod, "OpenGl_LayerFilter", "Tool object to specify processed OpenGL layers.")
	.value("OpenGl_LF_All", OpenGl_LayerFilter::OpenGl_LF_All)
	.value("OpenGl_LF_Upper", OpenGl_LayerFilter::OpenGl_LF_Upper)
	.value("OpenGl_LF_Bottom", OpenGl_LayerFilter::OpenGl_LF_Bottom)
	.value("OpenGl_LF_Default", OpenGl_LayerFilter::OpenGl_LF_Default)
	.export_values();


}