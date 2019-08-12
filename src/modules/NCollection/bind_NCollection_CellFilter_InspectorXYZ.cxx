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
#include <gp_XY.hxx>
#include <gp_XYZ.hxx>
#include <Standard_TypeDef.hxx>
#include <NCollection_CellFilter.hxx>

void bind_NCollection_CellFilter_InspectorXYZ(py::module &mod){

py::class_<NCollection_CellFilter_InspectorXYZ, std::unique_ptr<NCollection_CellFilter_InspectorXYZ, Deleter<NCollection_CellFilter_InspectorXYZ>>> cls_NCollection_CellFilter_InspectorXYZ(mod, "NCollection_CellFilter_InspectorXYZ", "None");

// Constructors

// Fields

// Methods
cls_NCollection_CellFilter_InspectorXYZ.def_static("Coord_", (Standard_Real (*)(int, const NCollection_CellFilter_InspectorXYZ::Point &)) &NCollection_CellFilter_InspectorXYZ::Coord, "Access to co-ordinate", py::arg("i"), py::arg("thePnt"));
cls_NCollection_CellFilter_InspectorXYZ.def("Shift", (NCollection_CellFilter_InspectorXYZ::Point (NCollection_CellFilter_InspectorXYZ::*)(const NCollection_CellFilter_InspectorXYZ::Point &, Standard_Real) const) &NCollection_CellFilter_InspectorXYZ::Shift, "Auxiliary method to shift point by each coordinate on given value; useful for preparing a points range for Inspect with tolerance", py::arg("thePnt"), py::arg("theTol"));

// Enums
cls_NCollection_CellFilter_InspectorXYZ.attr("Dimension") = py::cast(int(NCollection_CellFilter_InspectorXYZ::Dimension));

}