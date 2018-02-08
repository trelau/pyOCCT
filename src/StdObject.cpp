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

#include <StdObjMgt_Persistent.hxx>
#include <TopLoc_Location.hxx>
#include <StdObject_Location.hxx>
#include <StdObjMgt_TransientPersistentMap.hxx>
#include <StdObject_gp_Trsfs.hxx>
#include <StdObjMgt_ReadData.hxx>
#include <gp_Trsf.hxx>
#include <StdObjMgt_WriteData.hxx>
#include <TopoDS_Shape.hxx>
#include <StdObject_Shape.hxx>
#include <StdObject_gp_Axes.hxx>
#include <gp_Ax1.hxx>

PYBIND11_MODULE(StdObject, mod) {

	// IMPORT
	py::module::import("OCCT.StdObjMgt");
	py::module::import("OCCT.TopLoc");
	py::module::import("OCCT.gp");
	py::module::import("OCCT.TopoDS");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS
	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\StdObject_gp_Trsfs.hxx
	mod.def("bits_right", (StdObjMgt_ReadData & (*)(StdObjMgt_ReadData::Object, gp_Trsf &)) &operator>>, py::is_operator(), "None", py::arg("theReadData"), py::arg("theTrsf"));
	*/
	/* FIXME
	// C:\Miniconda\envs\occt\Library\include\opencascade\StdObject_gp_Trsfs.hxx
	mod.def("bits_left", (StdObjMgt_WriteData & (*)(StdObjMgt_WriteData::Object, const gp_Trsf &)) &operator<<, py::is_operator(), "None", py::arg("theWriteData"), py::arg("theTrsf"));
	*/
	// C:\Miniconda\envs\occt\Library\include\opencascade\StdObject_gp_Axes.hxx
	mod.def("write", (StdObjMgt_WriteData & (*)(StdObjMgt_WriteData::Object, const gp_Ax1 &)) &write, "None", py::arg("theWriteData"), py::arg("theAx"));


	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\StdObject_Location.hxx
	py::class_<StdObject_Location, std::unique_ptr<StdObject_Location, Deleter<StdObject_Location>>> cls_StdObject_Location(mod, "StdObject_Location", "None");
	cls_StdObject_Location.def(py::init<>());
	cls_StdObject_Location.def("PChildren", (void (StdObject_Location::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const ) &StdObject_Location::PChildren, "Gets persistent child objects", py::arg("theChildren"));
	cls_StdObject_Location.def("Import", (TopLoc_Location (StdObject_Location::*)() const ) &StdObject_Location::Import, "Import transient object from the persistent data.");
	cls_StdObject_Location.def_static("Translate_", (StdObject_Location (*)(const TopLoc_Location &, StdObjMgt_TransientPersistentMap &)) &StdObject_Location::Translate, "Creates a persistent wrapper object for a location", py::arg("theLoc"), py::arg("theMap"));

	// C:\Miniconda\envs\occt\Library\include\opencascade\StdObject_Shape.hxx
	py::class_<StdObject_Shape, std::unique_ptr<StdObject_Shape, Deleter<StdObject_Shape>>> cls_StdObject_Shape(mod, "StdObject_Shape", "None");
	cls_StdObject_Shape.def(py::init<>());
	cls_StdObject_Shape.def("Import", (TopoDS_Shape (StdObject_Shape::*)() const ) &StdObject_Shape::Import, "Import transient object from the persistent data.");
	cls_StdObject_Shape.def("PChildren", (void (StdObject_Shape::*)(StdObjMgt_Persistent::SequenceOfPersistent &) const ) &StdObject_Shape::PChildren, "None", py::arg("theChildren"));


}
