/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC (info@laughlinresearch.com)

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
#include <pyOCCT_Common.hpp>

#include <TopoDS_Shape.hxx>
#include <gp_Dir.hxx>
#include <gp_Pnt.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Wire.hxx>
#include <TopoDS_Compound.hxx>
#include <BRepProj_Projection.hxx>

PYBIND11_MODULE(BRepProj, mod) {

	// IMPORT
	py::module::import("OCCT.TopoDS");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.Standard");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\BRepProj_Projection.hxx
	py::class_<BRepProj_Projection, std::unique_ptr<BRepProj_Projection, Deleter<BRepProj_Projection>>> cls_BRepProj_Projection(mod, "BRepProj_Projection", "The Projection class provides conical and cylindrical projections of Edge or Wire on a Shape from TopoDS. The result will be a Edge or Wire from TopoDS.");
	cls_BRepProj_Projection.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const gp_Dir &>(), py::arg("Wire"), py::arg("Shape"), py::arg("D"));
	cls_BRepProj_Projection.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const gp_Pnt &>(), py::arg("Wire"), py::arg("Shape"), py::arg("P"));
	cls_BRepProj_Projection.def("IsDone", (Standard_Boolean (BRepProj_Projection::*)() const ) &BRepProj_Projection::IsDone, "returns False if the section failed");
	cls_BRepProj_Projection.def("Init", (void (BRepProj_Projection::*)()) &BRepProj_Projection::Init, "Resets the iterator by resulting wires.");
	cls_BRepProj_Projection.def("More", (Standard_Boolean (BRepProj_Projection::*)() const ) &BRepProj_Projection::More, "Returns True if there is a current result wire");
	cls_BRepProj_Projection.def("Next", (void (BRepProj_Projection::*)()) &BRepProj_Projection::Next, "Move to the next result wire.");
	cls_BRepProj_Projection.def("Current", (TopoDS_Wire (BRepProj_Projection::*)() const ) &BRepProj_Projection::Current, "Returns the current result wire.");
	cls_BRepProj_Projection.def("Shape", (TopoDS_Compound (BRepProj_Projection::*)() const ) &BRepProj_Projection::Shape, "Returns the complete result as compound of wires.");


}
