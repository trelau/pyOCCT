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
#include <BRepMesh.hxx>
#include <BRepMesh_Status.hxx>
#include <Standard_Mutex.hxx>
#include <Standard_TypeDef.hxx>
#include <BRepMesh_WireInterferenceChecker.hxx>

void bind_BRepMesh_WireInterferenceChecker(py::module &mod){

py::class_<BRepMesh_WireInterferenceChecker, std::unique_ptr<BRepMesh_WireInterferenceChecker>> cls_BRepMesh_WireInterferenceChecker(mod, "BRepMesh_WireInterferenceChecker", "Auxilary class implementing functionality for checking interference between two discretized wires.");

// Constructors
// cls_BRepMesh_WireInterferenceChecker.def(py::init<const BRepMesh::Array1OfSegmentsTree &, BRepMesh_Status *>(), py::arg("theWires"), py::arg("theStatus"));
// cls_BRepMesh_WireInterferenceChecker.def(py::init<const BRepMesh::Array1OfSegmentsTree &, BRepMesh_Status *, Standard_Mutex *>(), py::arg("theWires"), py::arg("theStatus"), py::arg("theMutex"));

// Fields

// Methods
// cls_BRepMesh_WireInterferenceChecker.def("__call__", (void (BRepMesh_WireInterferenceChecker::*)(const Standard_Integer &) const) &BRepMesh_WireInterferenceChecker::operator(), py::is_operator(), "Checker's body.", py::arg("theWireId"));

// Enums
py::enum_<BRepMesh_WireInterferenceChecker::IntFlag>(cls_BRepMesh_WireInterferenceChecker, "IntFlag", "Enumerates states of segments intersection check.")
	.value("NoIntersection", BRepMesh_WireInterferenceChecker::IntFlag::NoIntersection)
	.value("Cross", BRepMesh_WireInterferenceChecker::IntFlag::Cross)
	.value("EndPointTouch", BRepMesh_WireInterferenceChecker::IntFlag::EndPointTouch)
	.value("PointOnSegment", BRepMesh_WireInterferenceChecker::IntFlag::PointOnSegment)
	.value("Glued", BRepMesh_WireInterferenceChecker::IntFlag::Glued)
	.value("Same", BRepMesh_WireInterferenceChecker::IntFlag::Same)
	.export_values();

}