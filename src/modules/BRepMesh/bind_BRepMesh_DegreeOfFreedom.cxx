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
#include <BRepMesh_DegreeOfFreedom.hxx>

void bind_BRepMesh_DegreeOfFreedom(py::module &mod){

py::enum_<BRepMesh_DegreeOfFreedom>(mod, "BRepMesh_DegreeOfFreedom", "None")
	.value("BRepMesh_Free", BRepMesh_DegreeOfFreedom::BRepMesh_Free)
	.value("BRepMesh_InVolume", BRepMesh_DegreeOfFreedom::BRepMesh_InVolume)
	.value("BRepMesh_OnSurface", BRepMesh_DegreeOfFreedom::BRepMesh_OnSurface)
	.value("BRepMesh_OnCurve", BRepMesh_DegreeOfFreedom::BRepMesh_OnCurve)
	.value("BRepMesh_Fixed", BRepMesh_DegreeOfFreedom::BRepMesh_Fixed)
	.value("BRepMesh_Frontier", BRepMesh_DegreeOfFreedom::BRepMesh_Frontier)
	.value("BRepMesh_Deleted", BRepMesh_DegreeOfFreedom::BRepMesh_Deleted)
	.export_values();


}