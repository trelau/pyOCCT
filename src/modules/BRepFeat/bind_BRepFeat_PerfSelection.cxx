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
#include <BRepFeat_PerfSelection.hxx>

void bind_BRepFeat_PerfSelection(py::module &mod){

py::enum_<BRepFeat_PerfSelection>(mod, "BRepFeat_PerfSelection", "To declare the type of selection semantics for local operation Perform methods - NoSelection - SelectionFU - selection of a face up to which a local operation will be performed - SelectionU - selection of a point up to which a local operation will be performed - SelectionSh - selection of a shape on which a local operation will be performed - SelectionShU - selection of a shape up to which a local operation will be performed.")
	.value("BRepFeat_NoSelection", BRepFeat_PerfSelection::BRepFeat_NoSelection)
	.value("BRepFeat_SelectionFU", BRepFeat_PerfSelection::BRepFeat_SelectionFU)
	.value("BRepFeat_SelectionU", BRepFeat_PerfSelection::BRepFeat_SelectionU)
	.value("BRepFeat_SelectionSh", BRepFeat_PerfSelection::BRepFeat_SelectionSh)
	.value("BRepFeat_SelectionShU", BRepFeat_PerfSelection::BRepFeat_SelectionShU)
	.export_values();


}