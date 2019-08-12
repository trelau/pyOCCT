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
#include <VrmlAPI_RepresentationOfShape.hxx>

void bind_VrmlAPI_RepresentationOfShape(py::module &mod){

py::enum_<VrmlAPI_RepresentationOfShape>(mod, "VrmlAPI_RepresentationOfShape", "Identifies the representation of the shape written to a VRML file. The available options are : - VrmlAPI_ShadedRepresentation : the shape is translated with a shaded representation. - VrmlAPI_WireFrameRepresentation : the shape is translated with a wireframe representation. - VrmlAPI_BothRepresentation : the shape is translated to VRML format with both representations : shaded and wireframe. This is the default option.")
	.value("VrmlAPI_ShadedRepresentation", VrmlAPI_RepresentationOfShape::VrmlAPI_ShadedRepresentation)
	.value("VrmlAPI_WireFrameRepresentation", VrmlAPI_RepresentationOfShape::VrmlAPI_WireFrameRepresentation)
	.value("VrmlAPI_BothRepresentation", VrmlAPI_RepresentationOfShape::VrmlAPI_BothRepresentation)
	.export_values();


}