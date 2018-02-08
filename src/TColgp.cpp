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

#include <Standard_TypeDef.hxx>
#include <NCollection_Array1.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Type.hxx>
#include <TColgp_HArray1OfPnt2d.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <NCollection_Array2.hxx>
#include <TColgp_Array2OfPnt.hxx>
#include <TColgp_HArray2OfPnt.hxx>
#include <TColgp_Array2OfPnt2d.hxx>
#include <TColgp_HArray2OfPnt2d.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <NCollection_BaseSequence.hxx>
#include <NCollection_Sequence.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <TColgp_HSequenceOfPnt.hxx>
#include <TColgp_Array1OfDir.hxx>
#include <TColgp_HArray1OfDir.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColgp_HArray1OfVec.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <TColgp_HArray1OfVec2d.hxx>
#include <TColgp_SequenceOfArray1OfPnt2d.hxx>
#include <TColgp_Array2OfXYZ.hxx>
#include <TColgp_HArray2OfXYZ.hxx>
#include <TColgp_Array1OfXYZ.hxx>
#include <TColgp_SequenceOfXY.hxx>
#include <TColgp_SequenceOfXYZ.hxx>
#include <TColgp_SequenceOfPnt2d.hxx>
#include <TColgp_SequenceOfAx1.hxx>
#include <TColgp_HSequenceOfXY.hxx>
#include <TColgp_Array2OfVec.hxx>
#include <TColgp_Array1OfXY.hxx>
#include <TColgp_Array1OfCirc2d.hxx>
#include <TColgp_Array1OfLin2d.hxx>
#include <TColgp_SequenceOfVec.hxx>
#include <TColgp_HArray1OfXYZ.hxx>
#include <TColgp_HArray1OfXY.hxx>
#include <TColgp_HSequenceOfXYZ.hxx>
#include <TColgp_Array1OfDir2d.hxx>
#include <TColgp_HArray1OfDir2d.hxx>
#include <TColgp_HArray1OfLin2d.hxx>
#include <TColgp_HArray1OfCirc2d.hxx>
#include <TColgp_Array2OfDir.hxx>
#include <TColgp_HArray2OfDir.hxx>
#include <TColgp_HArray2OfVec.hxx>
#include <TColgp_Array2OfXY.hxx>
#include <TColgp_HArray2OfXY.hxx>
#include <TColgp_Array2OfDir2d.hxx>
#include <TColgp_HArray2OfDir2d.hxx>
#include <TColgp_Array2OfVec2d.hxx>
#include <TColgp_HArray2OfVec2d.hxx>
#include <TColgp_Array2OfLin2d.hxx>
#include <TColgp_HArray2OfLin2d.hxx>
#include <TColgp_Array2OfCirc2d.hxx>
#include <TColgp_HArray2OfCirc2d.hxx>
#include <TColgp_SequenceOfDir.hxx>
#include <TColgp_HSequenceOfDir.hxx>
#include <TColgp_HSequenceOfVec.hxx>
#include <TColgp_SequenceOfDir2d.hxx>
#include <TColgp_HSequenceOfDir2d.hxx>
#include <TColgp_HSequenceOfPnt2d.hxx>
#include <TColgp_SequenceOfVec2d.hxx>
#include <TColgp_HSequenceOfVec2d.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(TColgp, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_Array1OfPnt2d.hxx
	bind_NCollection_Array1<gp_Pnt2d>(mod, "TColgp_Array1OfPnt2d");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_Array2OfPnt.hxx
	bind_NCollection_Array2<gp_Pnt>(mod, "TColgp_Array2OfPnt");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_Array2OfPnt2d.hxx
	bind_NCollection_Array2<gp_Pnt2d>(mod, "TColgp_Array2OfPnt2d");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_Array1OfPnt.hxx
	bind_NCollection_Array1<gp_Pnt>(mod, "TColgp_Array1OfPnt");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_SequenceOfPnt.hxx
	bind_NCollection_Sequence<gp_Pnt>(mod, "TColgp_SequenceOfPnt");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_Array1OfDir.hxx
	bind_NCollection_Array1<gp_Dir>(mod, "TColgp_Array1OfDir");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_Array1OfVec.hxx
	bind_NCollection_Array1<gp_Vec>(mod, "TColgp_Array1OfVec");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_Array1OfVec2d.hxx
	bind_NCollection_Array1<gp_Vec2d>(mod, "TColgp_Array1OfVec2d");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_Array2OfXYZ.hxx
	bind_NCollection_Array2<gp_XYZ>(mod, "TColgp_Array2OfXYZ");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_SequenceOfXY.hxx
	bind_NCollection_Sequence<gp_XY>(mod, "TColgp_SequenceOfXY");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_Array1OfXYZ.hxx
	bind_NCollection_Array1<gp_XYZ>(mod, "TColgp_Array1OfXYZ");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_Array1OfXY.hxx
	bind_NCollection_Array1<gp_XY>(mod, "TColgp_Array1OfXY");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_SequenceOfXYZ.hxx
	bind_NCollection_Sequence<gp_XYZ>(mod, "TColgp_SequenceOfXYZ");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_Array1OfDir2d.hxx
	bind_NCollection_Array1<gp_Dir2d>(mod, "TColgp_Array1OfDir2d");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_Array1OfLin2d.hxx
	bind_NCollection_Array1<gp_Lin2d>(mod, "TColgp_Array1OfLin2d");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_Array1OfCirc2d.hxx
	bind_NCollection_Array1<gp_Circ2d>(mod, "TColgp_Array1OfCirc2d");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_Array2OfDir.hxx
	bind_NCollection_Array2<gp_Dir>(mod, "TColgp_Array2OfDir");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_Array2OfVec.hxx
	bind_NCollection_Array2<gp_Vec>(mod, "TColgp_Array2OfVec");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_Array2OfXY.hxx
	bind_NCollection_Array2<gp_XY>(mod, "TColgp_Array2OfXY");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_Array2OfDir2d.hxx
	bind_NCollection_Array2<gp_Dir2d>(mod, "TColgp_Array2OfDir2d");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_Array2OfVec2d.hxx
	bind_NCollection_Array2<gp_Vec2d>(mod, "TColgp_Array2OfVec2d");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_Array2OfLin2d.hxx
	bind_NCollection_Array2<gp_Lin2d>(mod, "TColgp_Array2OfLin2d");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_Array2OfCirc2d.hxx
	bind_NCollection_Array2<gp_Circ2d>(mod, "TColgp_Array2OfCirc2d");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_SequenceOfDir.hxx
	bind_NCollection_Sequence<gp_Dir>(mod, "TColgp_SequenceOfDir");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_SequenceOfVec.hxx
	bind_NCollection_Sequence<gp_Vec>(mod, "TColgp_SequenceOfVec");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_SequenceOfDir2d.hxx
	bind_NCollection_Sequence<gp_Dir2d>(mod, "TColgp_SequenceOfDir2d");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_SequenceOfPnt2d.hxx
	bind_NCollection_Sequence<gp_Pnt2d>(mod, "TColgp_SequenceOfPnt2d");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_SequenceOfVec2d.hxx
	bind_NCollection_Sequence<gp_Vec2d>(mod, "TColgp_SequenceOfVec2d");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray1OfPnt2d.hxx
	py::class_<TColgp_HArray1OfPnt2d, opencascade::handle<TColgp_HArray1OfPnt2d>, TColgp_Array1OfPnt2d, Standard_Transient> cls_TColgp_HArray1OfPnt2d(mod, "TColgp_HArray1OfPnt2d", "None");
	cls_TColgp_HArray1OfPnt2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_HArray1OfPnt2d.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfPnt2d::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColgp_HArray1OfPnt2d.def(py::init<const TColgp_Array1OfPnt2d &>(), py::arg("theOther"));
	cls_TColgp_HArray1OfPnt2d.def("Array1", (const TColgp_Array1OfPnt2d & (TColgp_HArray1OfPnt2d::*)() const ) &TColgp_HArray1OfPnt2d::Array1, "None");
	cls_TColgp_HArray1OfPnt2d.def("ChangeArray1", (TColgp_Array1OfPnt2d & (TColgp_HArray1OfPnt2d::*)()) &TColgp_HArray1OfPnt2d::ChangeArray1, "None");
	cls_TColgp_HArray1OfPnt2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfPnt2d::get_type_name, "None");
	cls_TColgp_HArray1OfPnt2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfPnt2d::get_type_descriptor, "None");
	cls_TColgp_HArray1OfPnt2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfPnt2d::*)() const ) &TColgp_HArray1OfPnt2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray1OfPnt.hxx
	py::class_<TColgp_HArray1OfPnt, opencascade::handle<TColgp_HArray1OfPnt>, TColgp_Array1OfPnt, Standard_Transient> cls_TColgp_HArray1OfPnt(mod, "TColgp_HArray1OfPnt", "None");
	cls_TColgp_HArray1OfPnt.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_HArray1OfPnt.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfPnt::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColgp_HArray1OfPnt.def(py::init<const TColgp_Array1OfPnt &>(), py::arg("theOther"));
	cls_TColgp_HArray1OfPnt.def("Array1", (const TColgp_Array1OfPnt & (TColgp_HArray1OfPnt::*)() const ) &TColgp_HArray1OfPnt::Array1, "None");
	cls_TColgp_HArray1OfPnt.def("ChangeArray1", (TColgp_Array1OfPnt & (TColgp_HArray1OfPnt::*)()) &TColgp_HArray1OfPnt::ChangeArray1, "None");
	cls_TColgp_HArray1OfPnt.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfPnt::get_type_name, "None");
	cls_TColgp_HArray1OfPnt.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfPnt::get_type_descriptor, "None");
	cls_TColgp_HArray1OfPnt.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfPnt::*)() const ) &TColgp_HArray1OfPnt::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray2OfPnt.hxx
	py::class_<TColgp_HArray2OfPnt, opencascade::handle<TColgp_HArray2OfPnt>, TColgp_Array2OfPnt, Standard_Transient> cls_TColgp_HArray2OfPnt(mod, "TColgp_HArray2OfPnt", "None");
	cls_TColgp_HArray2OfPnt.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColgp_HArray2OfPnt.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfPnt::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColgp_HArray2OfPnt.def(py::init<const TColgp_Array2OfPnt &>(), py::arg("theOther"));
	cls_TColgp_HArray2OfPnt.def("Array2", (const TColgp_Array2OfPnt & (TColgp_HArray2OfPnt::*)() const ) &TColgp_HArray2OfPnt::Array2, "None");
	cls_TColgp_HArray2OfPnt.def("ChangeArray2", (TColgp_Array2OfPnt & (TColgp_HArray2OfPnt::*)()) &TColgp_HArray2OfPnt::ChangeArray2, "None");
	cls_TColgp_HArray2OfPnt.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfPnt::get_type_name, "None");
	cls_TColgp_HArray2OfPnt.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfPnt::get_type_descriptor, "None");
	cls_TColgp_HArray2OfPnt.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfPnt::*)() const ) &TColgp_HArray2OfPnt::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray2OfPnt2d.hxx
	py::class_<TColgp_HArray2OfPnt2d, opencascade::handle<TColgp_HArray2OfPnt2d>, TColgp_Array2OfPnt2d, Standard_Transient> cls_TColgp_HArray2OfPnt2d(mod, "TColgp_HArray2OfPnt2d", "None");
	cls_TColgp_HArray2OfPnt2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColgp_HArray2OfPnt2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfPnt2d::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColgp_HArray2OfPnt2d.def(py::init<const TColgp_Array2OfPnt2d &>(), py::arg("theOther"));
	cls_TColgp_HArray2OfPnt2d.def("Array2", (const TColgp_Array2OfPnt2d & (TColgp_HArray2OfPnt2d::*)() const ) &TColgp_HArray2OfPnt2d::Array2, "None");
	cls_TColgp_HArray2OfPnt2d.def("ChangeArray2", (TColgp_Array2OfPnt2d & (TColgp_HArray2OfPnt2d::*)()) &TColgp_HArray2OfPnt2d::ChangeArray2, "None");
	cls_TColgp_HArray2OfPnt2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfPnt2d::get_type_name, "None");
	cls_TColgp_HArray2OfPnt2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfPnt2d::get_type_descriptor, "None");
	cls_TColgp_HArray2OfPnt2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfPnt2d::*)() const ) &TColgp_HArray2OfPnt2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HSequenceOfPnt.hxx
	py::class_<TColgp_HSequenceOfPnt, opencascade::handle<TColgp_HSequenceOfPnt>, TColgp_SequenceOfPnt, Standard_Transient> cls_TColgp_HSequenceOfPnt(mod, "TColgp_HSequenceOfPnt", "None");
	cls_TColgp_HSequenceOfPnt.def(py::init<>());
	cls_TColgp_HSequenceOfPnt.def(py::init<const TColgp_SequenceOfPnt &>(), py::arg("theOther"));
	cls_TColgp_HSequenceOfPnt.def("Sequence", (const TColgp_SequenceOfPnt & (TColgp_HSequenceOfPnt::*)() const ) &TColgp_HSequenceOfPnt::Sequence, "None");
	cls_TColgp_HSequenceOfPnt.def("Append", (void (TColgp_HSequenceOfPnt::*)(const TColgp_SequenceOfPnt::value_type &)) &TColgp_HSequenceOfPnt::Append, "None", py::arg("theItem"));
	cls_TColgp_HSequenceOfPnt.def("Append", (void (TColgp_HSequenceOfPnt::*)(TColgp_SequenceOfPnt &)) &TColgp_HSequenceOfPnt::Append, "None", py::arg("theSequence"));
	cls_TColgp_HSequenceOfPnt.def("ChangeSequence", (TColgp_SequenceOfPnt & (TColgp_HSequenceOfPnt::*)()) &TColgp_HSequenceOfPnt::ChangeSequence, "None");
	cls_TColgp_HSequenceOfPnt.def_static("get_type_name_", (const char * (*)()) &TColgp_HSequenceOfPnt::get_type_name, "None");
	cls_TColgp_HSequenceOfPnt.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HSequenceOfPnt::get_type_descriptor, "None");
	cls_TColgp_HSequenceOfPnt.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HSequenceOfPnt::*)() const ) &TColgp_HSequenceOfPnt::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray1OfDir.hxx
	py::class_<TColgp_HArray1OfDir, opencascade::handle<TColgp_HArray1OfDir>, TColgp_Array1OfDir, Standard_Transient> cls_TColgp_HArray1OfDir(mod, "TColgp_HArray1OfDir", "None");
	cls_TColgp_HArray1OfDir.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_HArray1OfDir.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfDir::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColgp_HArray1OfDir.def(py::init<const TColgp_Array1OfDir &>(), py::arg("theOther"));
	cls_TColgp_HArray1OfDir.def("Array1", (const TColgp_Array1OfDir & (TColgp_HArray1OfDir::*)() const ) &TColgp_HArray1OfDir::Array1, "None");
	cls_TColgp_HArray1OfDir.def("ChangeArray1", (TColgp_Array1OfDir & (TColgp_HArray1OfDir::*)()) &TColgp_HArray1OfDir::ChangeArray1, "None");
	cls_TColgp_HArray1OfDir.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfDir::get_type_name, "None");
	cls_TColgp_HArray1OfDir.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfDir::get_type_descriptor, "None");
	cls_TColgp_HArray1OfDir.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfDir::*)() const ) &TColgp_HArray1OfDir::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray1OfVec.hxx
	py::class_<TColgp_HArray1OfVec, opencascade::handle<TColgp_HArray1OfVec>, TColgp_Array1OfVec, Standard_Transient> cls_TColgp_HArray1OfVec(mod, "TColgp_HArray1OfVec", "None");
	cls_TColgp_HArray1OfVec.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_HArray1OfVec.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfVec::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColgp_HArray1OfVec.def(py::init<const TColgp_Array1OfVec &>(), py::arg("theOther"));
	cls_TColgp_HArray1OfVec.def("Array1", (const TColgp_Array1OfVec & (TColgp_HArray1OfVec::*)() const ) &TColgp_HArray1OfVec::Array1, "None");
	cls_TColgp_HArray1OfVec.def("ChangeArray1", (TColgp_Array1OfVec & (TColgp_HArray1OfVec::*)()) &TColgp_HArray1OfVec::ChangeArray1, "None");
	cls_TColgp_HArray1OfVec.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfVec::get_type_name, "None");
	cls_TColgp_HArray1OfVec.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfVec::get_type_descriptor, "None");
	cls_TColgp_HArray1OfVec.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfVec::*)() const ) &TColgp_HArray1OfVec::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray1OfVec2d.hxx
	py::class_<TColgp_HArray1OfVec2d, opencascade::handle<TColgp_HArray1OfVec2d>, TColgp_Array1OfVec2d, Standard_Transient> cls_TColgp_HArray1OfVec2d(mod, "TColgp_HArray1OfVec2d", "None");
	cls_TColgp_HArray1OfVec2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_HArray1OfVec2d.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfVec2d::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColgp_HArray1OfVec2d.def(py::init<const TColgp_Array1OfVec2d &>(), py::arg("theOther"));
	cls_TColgp_HArray1OfVec2d.def("Array1", (const TColgp_Array1OfVec2d & (TColgp_HArray1OfVec2d::*)() const ) &TColgp_HArray1OfVec2d::Array1, "None");
	cls_TColgp_HArray1OfVec2d.def("ChangeArray1", (TColgp_Array1OfVec2d & (TColgp_HArray1OfVec2d::*)()) &TColgp_HArray1OfVec2d::ChangeArray1, "None");
	cls_TColgp_HArray1OfVec2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfVec2d::get_type_name, "None");
	cls_TColgp_HArray1OfVec2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfVec2d::get_type_descriptor, "None");
	cls_TColgp_HArray1OfVec2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfVec2d::*)() const ) &TColgp_HArray1OfVec2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_SequenceOfArray1OfPnt2d.hxx
	bind_NCollection_Sequence<opencascade::handle<TColgp_HArray1OfPnt2d> >(mod, "TColgp_SequenceOfArray1OfPnt2d");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray2OfXYZ.hxx
	py::class_<TColgp_HArray2OfXYZ, opencascade::handle<TColgp_HArray2OfXYZ>, TColgp_Array2OfXYZ, Standard_Transient> cls_TColgp_HArray2OfXYZ(mod, "TColgp_HArray2OfXYZ", "None");
	cls_TColgp_HArray2OfXYZ.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColgp_HArray2OfXYZ.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfXYZ::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColgp_HArray2OfXYZ.def(py::init<const TColgp_Array2OfXYZ &>(), py::arg("theOther"));
	cls_TColgp_HArray2OfXYZ.def("Array2", (const TColgp_Array2OfXYZ & (TColgp_HArray2OfXYZ::*)() const ) &TColgp_HArray2OfXYZ::Array2, "None");
	cls_TColgp_HArray2OfXYZ.def("ChangeArray2", (TColgp_Array2OfXYZ & (TColgp_HArray2OfXYZ::*)()) &TColgp_HArray2OfXYZ::ChangeArray2, "None");
	cls_TColgp_HArray2OfXYZ.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfXYZ::get_type_name, "None");
	cls_TColgp_HArray2OfXYZ.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfXYZ::get_type_descriptor, "None");
	cls_TColgp_HArray2OfXYZ.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfXYZ::*)() const ) &TColgp_HArray2OfXYZ::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray1OfXYZ.hxx
	py::class_<TColgp_HArray1OfXYZ, opencascade::handle<TColgp_HArray1OfXYZ>, TColgp_Array1OfXYZ, Standard_Transient> cls_TColgp_HArray1OfXYZ(mod, "TColgp_HArray1OfXYZ", "None");
	cls_TColgp_HArray1OfXYZ.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_HArray1OfXYZ.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfXYZ::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColgp_HArray1OfXYZ.def(py::init<const TColgp_Array1OfXYZ &>(), py::arg("theOther"));
	cls_TColgp_HArray1OfXYZ.def("Array1", (const TColgp_Array1OfXYZ & (TColgp_HArray1OfXYZ::*)() const ) &TColgp_HArray1OfXYZ::Array1, "None");
	cls_TColgp_HArray1OfXYZ.def("ChangeArray1", (TColgp_Array1OfXYZ & (TColgp_HArray1OfXYZ::*)()) &TColgp_HArray1OfXYZ::ChangeArray1, "None");
	cls_TColgp_HArray1OfXYZ.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfXYZ::get_type_name, "None");
	cls_TColgp_HArray1OfXYZ.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfXYZ::get_type_descriptor, "None");
	cls_TColgp_HArray1OfXYZ.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfXYZ::*)() const ) &TColgp_HArray1OfXYZ::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HSequenceOfXY.hxx
	py::class_<TColgp_HSequenceOfXY, opencascade::handle<TColgp_HSequenceOfXY>, TColgp_SequenceOfXY, Standard_Transient> cls_TColgp_HSequenceOfXY(mod, "TColgp_HSequenceOfXY", "None");
	cls_TColgp_HSequenceOfXY.def(py::init<>());
	cls_TColgp_HSequenceOfXY.def(py::init<const TColgp_SequenceOfXY &>(), py::arg("theOther"));
	cls_TColgp_HSequenceOfXY.def("Sequence", (const TColgp_SequenceOfXY & (TColgp_HSequenceOfXY::*)() const ) &TColgp_HSequenceOfXY::Sequence, "None");
	cls_TColgp_HSequenceOfXY.def("Append", (void (TColgp_HSequenceOfXY::*)(const TColgp_SequenceOfXY::value_type &)) &TColgp_HSequenceOfXY::Append, "None", py::arg("theItem"));
	cls_TColgp_HSequenceOfXY.def("Append", (void (TColgp_HSequenceOfXY::*)(TColgp_SequenceOfXY &)) &TColgp_HSequenceOfXY::Append, "None", py::arg("theSequence"));
	cls_TColgp_HSequenceOfXY.def("ChangeSequence", (TColgp_SequenceOfXY & (TColgp_HSequenceOfXY::*)()) &TColgp_HSequenceOfXY::ChangeSequence, "None");
	cls_TColgp_HSequenceOfXY.def_static("get_type_name_", (const char * (*)()) &TColgp_HSequenceOfXY::get_type_name, "None");
	cls_TColgp_HSequenceOfXY.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HSequenceOfXY::get_type_descriptor, "None");
	cls_TColgp_HSequenceOfXY.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HSequenceOfXY::*)() const ) &TColgp_HSequenceOfXY::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HSequenceOfXYZ.hxx
	py::class_<TColgp_HSequenceOfXYZ, opencascade::handle<TColgp_HSequenceOfXYZ>, TColgp_SequenceOfXYZ, Standard_Transient> cls_TColgp_HSequenceOfXYZ(mod, "TColgp_HSequenceOfXYZ", "None");
	cls_TColgp_HSequenceOfXYZ.def(py::init<>());
	cls_TColgp_HSequenceOfXYZ.def(py::init<const TColgp_SequenceOfXYZ &>(), py::arg("theOther"));
	cls_TColgp_HSequenceOfXYZ.def("Sequence", (const TColgp_SequenceOfXYZ & (TColgp_HSequenceOfXYZ::*)() const ) &TColgp_HSequenceOfXYZ::Sequence, "None");
	cls_TColgp_HSequenceOfXYZ.def("Append", (void (TColgp_HSequenceOfXYZ::*)(const TColgp_SequenceOfXYZ::value_type &)) &TColgp_HSequenceOfXYZ::Append, "None", py::arg("theItem"));
	cls_TColgp_HSequenceOfXYZ.def("Append", (void (TColgp_HSequenceOfXYZ::*)(TColgp_SequenceOfXYZ &)) &TColgp_HSequenceOfXYZ::Append, "None", py::arg("theSequence"));
	cls_TColgp_HSequenceOfXYZ.def("ChangeSequence", (TColgp_SequenceOfXYZ & (TColgp_HSequenceOfXYZ::*)()) &TColgp_HSequenceOfXYZ::ChangeSequence, "None");
	cls_TColgp_HSequenceOfXYZ.def_static("get_type_name_", (const char * (*)()) &TColgp_HSequenceOfXYZ::get_type_name, "None");
	cls_TColgp_HSequenceOfXYZ.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HSequenceOfXYZ::get_type_descriptor, "None");
	cls_TColgp_HSequenceOfXYZ.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HSequenceOfXYZ::*)() const ) &TColgp_HSequenceOfXYZ::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HSequenceOfPnt2d.hxx
	py::class_<TColgp_HSequenceOfPnt2d, opencascade::handle<TColgp_HSequenceOfPnt2d>, TColgp_SequenceOfPnt2d, Standard_Transient> cls_TColgp_HSequenceOfPnt2d(mod, "TColgp_HSequenceOfPnt2d", "None");
	cls_TColgp_HSequenceOfPnt2d.def(py::init<>());
	cls_TColgp_HSequenceOfPnt2d.def(py::init<const TColgp_SequenceOfPnt2d &>(), py::arg("theOther"));
	cls_TColgp_HSequenceOfPnt2d.def("Sequence", (const TColgp_SequenceOfPnt2d & (TColgp_HSequenceOfPnt2d::*)() const ) &TColgp_HSequenceOfPnt2d::Sequence, "None");
	cls_TColgp_HSequenceOfPnt2d.def("Append", (void (TColgp_HSequenceOfPnt2d::*)(const TColgp_SequenceOfPnt2d::value_type &)) &TColgp_HSequenceOfPnt2d::Append, "None", py::arg("theItem"));
	cls_TColgp_HSequenceOfPnt2d.def("Append", (void (TColgp_HSequenceOfPnt2d::*)(TColgp_SequenceOfPnt2d &)) &TColgp_HSequenceOfPnt2d::Append, "None", py::arg("theSequence"));
	cls_TColgp_HSequenceOfPnt2d.def("ChangeSequence", (TColgp_SequenceOfPnt2d & (TColgp_HSequenceOfPnt2d::*)()) &TColgp_HSequenceOfPnt2d::ChangeSequence, "None");
	cls_TColgp_HSequenceOfPnt2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HSequenceOfPnt2d::get_type_name, "None");
	cls_TColgp_HSequenceOfPnt2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HSequenceOfPnt2d::get_type_descriptor, "None");
	cls_TColgp_HSequenceOfPnt2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HSequenceOfPnt2d::*)() const ) &TColgp_HSequenceOfPnt2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_SequenceOfAx1.hxx
	bind_NCollection_Sequence<gp_Ax1>(mod, "TColgp_SequenceOfAx1");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray2OfVec.hxx
	py::class_<TColgp_HArray2OfVec, opencascade::handle<TColgp_HArray2OfVec>, TColgp_Array2OfVec, Standard_Transient> cls_TColgp_HArray2OfVec(mod, "TColgp_HArray2OfVec", "None");
	cls_TColgp_HArray2OfVec.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColgp_HArray2OfVec.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfVec::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColgp_HArray2OfVec.def(py::init<const TColgp_Array2OfVec &>(), py::arg("theOther"));
	cls_TColgp_HArray2OfVec.def("Array2", (const TColgp_Array2OfVec & (TColgp_HArray2OfVec::*)() const ) &TColgp_HArray2OfVec::Array2, "None");
	cls_TColgp_HArray2OfVec.def("ChangeArray2", (TColgp_Array2OfVec & (TColgp_HArray2OfVec::*)()) &TColgp_HArray2OfVec::ChangeArray2, "None");
	cls_TColgp_HArray2OfVec.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfVec::get_type_name, "None");
	cls_TColgp_HArray2OfVec.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfVec::get_type_descriptor, "None");
	cls_TColgp_HArray2OfVec.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfVec::*)() const ) &TColgp_HArray2OfVec::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray1OfXY.hxx
	py::class_<TColgp_HArray1OfXY, opencascade::handle<TColgp_HArray1OfXY>, TColgp_Array1OfXY, Standard_Transient> cls_TColgp_HArray1OfXY(mod, "TColgp_HArray1OfXY", "None");
	cls_TColgp_HArray1OfXY.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_HArray1OfXY.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfXY::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColgp_HArray1OfXY.def(py::init<const TColgp_Array1OfXY &>(), py::arg("theOther"));
	cls_TColgp_HArray1OfXY.def("Array1", (const TColgp_Array1OfXY & (TColgp_HArray1OfXY::*)() const ) &TColgp_HArray1OfXY::Array1, "None");
	cls_TColgp_HArray1OfXY.def("ChangeArray1", (TColgp_Array1OfXY & (TColgp_HArray1OfXY::*)()) &TColgp_HArray1OfXY::ChangeArray1, "None");
	cls_TColgp_HArray1OfXY.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfXY::get_type_name, "None");
	cls_TColgp_HArray1OfXY.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfXY::get_type_descriptor, "None");
	cls_TColgp_HArray1OfXY.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfXY::*)() const ) &TColgp_HArray1OfXY::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray1OfCirc2d.hxx
	py::class_<TColgp_HArray1OfCirc2d, opencascade::handle<TColgp_HArray1OfCirc2d>, TColgp_Array1OfCirc2d, Standard_Transient> cls_TColgp_HArray1OfCirc2d(mod, "TColgp_HArray1OfCirc2d", "None");
	cls_TColgp_HArray1OfCirc2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_HArray1OfCirc2d.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfCirc2d::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColgp_HArray1OfCirc2d.def(py::init<const TColgp_Array1OfCirc2d &>(), py::arg("theOther"));
	cls_TColgp_HArray1OfCirc2d.def("Array1", (const TColgp_Array1OfCirc2d & (TColgp_HArray1OfCirc2d::*)() const ) &TColgp_HArray1OfCirc2d::Array1, "None");
	cls_TColgp_HArray1OfCirc2d.def("ChangeArray1", (TColgp_Array1OfCirc2d & (TColgp_HArray1OfCirc2d::*)()) &TColgp_HArray1OfCirc2d::ChangeArray1, "None");
	cls_TColgp_HArray1OfCirc2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfCirc2d::get_type_name, "None");
	cls_TColgp_HArray1OfCirc2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfCirc2d::get_type_descriptor, "None");
	cls_TColgp_HArray1OfCirc2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfCirc2d::*)() const ) &TColgp_HArray1OfCirc2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray1OfLin2d.hxx
	py::class_<TColgp_HArray1OfLin2d, opencascade::handle<TColgp_HArray1OfLin2d>, TColgp_Array1OfLin2d, Standard_Transient> cls_TColgp_HArray1OfLin2d(mod, "TColgp_HArray1OfLin2d", "None");
	cls_TColgp_HArray1OfLin2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_HArray1OfLin2d.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfLin2d::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColgp_HArray1OfLin2d.def(py::init<const TColgp_Array1OfLin2d &>(), py::arg("theOther"));
	cls_TColgp_HArray1OfLin2d.def("Array1", (const TColgp_Array1OfLin2d & (TColgp_HArray1OfLin2d::*)() const ) &TColgp_HArray1OfLin2d::Array1, "None");
	cls_TColgp_HArray1OfLin2d.def("ChangeArray1", (TColgp_Array1OfLin2d & (TColgp_HArray1OfLin2d::*)()) &TColgp_HArray1OfLin2d::ChangeArray1, "None");
	cls_TColgp_HArray1OfLin2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfLin2d::get_type_name, "None");
	cls_TColgp_HArray1OfLin2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfLin2d::get_type_descriptor, "None");
	cls_TColgp_HArray1OfLin2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfLin2d::*)() const ) &TColgp_HArray1OfLin2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HSequenceOfVec.hxx
	py::class_<TColgp_HSequenceOfVec, opencascade::handle<TColgp_HSequenceOfVec>, TColgp_SequenceOfVec, Standard_Transient> cls_TColgp_HSequenceOfVec(mod, "TColgp_HSequenceOfVec", "None");
	cls_TColgp_HSequenceOfVec.def(py::init<>());
	cls_TColgp_HSequenceOfVec.def(py::init<const TColgp_SequenceOfVec &>(), py::arg("theOther"));
	cls_TColgp_HSequenceOfVec.def("Sequence", (const TColgp_SequenceOfVec & (TColgp_HSequenceOfVec::*)() const ) &TColgp_HSequenceOfVec::Sequence, "None");
	cls_TColgp_HSequenceOfVec.def("Append", (void (TColgp_HSequenceOfVec::*)(const TColgp_SequenceOfVec::value_type &)) &TColgp_HSequenceOfVec::Append, "None", py::arg("theItem"));
	cls_TColgp_HSequenceOfVec.def("Append", (void (TColgp_HSequenceOfVec::*)(TColgp_SequenceOfVec &)) &TColgp_HSequenceOfVec::Append, "None", py::arg("theSequence"));
	cls_TColgp_HSequenceOfVec.def("ChangeSequence", (TColgp_SequenceOfVec & (TColgp_HSequenceOfVec::*)()) &TColgp_HSequenceOfVec::ChangeSequence, "None");
	cls_TColgp_HSequenceOfVec.def_static("get_type_name_", (const char * (*)()) &TColgp_HSequenceOfVec::get_type_name, "None");
	cls_TColgp_HSequenceOfVec.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HSequenceOfVec::get_type_descriptor, "None");
	cls_TColgp_HSequenceOfVec.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HSequenceOfVec::*)() const ) &TColgp_HSequenceOfVec::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray1OfDir2d.hxx
	py::class_<TColgp_HArray1OfDir2d, opencascade::handle<TColgp_HArray1OfDir2d>, TColgp_Array1OfDir2d, Standard_Transient> cls_TColgp_HArray1OfDir2d(mod, "TColgp_HArray1OfDir2d", "None");
	cls_TColgp_HArray1OfDir2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColgp_HArray1OfDir2d.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfDir2d::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColgp_HArray1OfDir2d.def(py::init<const TColgp_Array1OfDir2d &>(), py::arg("theOther"));
	cls_TColgp_HArray1OfDir2d.def("Array1", (const TColgp_Array1OfDir2d & (TColgp_HArray1OfDir2d::*)() const ) &TColgp_HArray1OfDir2d::Array1, "None");
	cls_TColgp_HArray1OfDir2d.def("ChangeArray1", (TColgp_Array1OfDir2d & (TColgp_HArray1OfDir2d::*)()) &TColgp_HArray1OfDir2d::ChangeArray1, "None");
	cls_TColgp_HArray1OfDir2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfDir2d::get_type_name, "None");
	cls_TColgp_HArray1OfDir2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfDir2d::get_type_descriptor, "None");
	cls_TColgp_HArray1OfDir2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfDir2d::*)() const ) &TColgp_HArray1OfDir2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray2OfDir.hxx
	py::class_<TColgp_HArray2OfDir, opencascade::handle<TColgp_HArray2OfDir>, TColgp_Array2OfDir, Standard_Transient> cls_TColgp_HArray2OfDir(mod, "TColgp_HArray2OfDir", "None");
	cls_TColgp_HArray2OfDir.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColgp_HArray2OfDir.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfDir::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColgp_HArray2OfDir.def(py::init<const TColgp_Array2OfDir &>(), py::arg("theOther"));
	cls_TColgp_HArray2OfDir.def("Array2", (const TColgp_Array2OfDir & (TColgp_HArray2OfDir::*)() const ) &TColgp_HArray2OfDir::Array2, "None");
	cls_TColgp_HArray2OfDir.def("ChangeArray2", (TColgp_Array2OfDir & (TColgp_HArray2OfDir::*)()) &TColgp_HArray2OfDir::ChangeArray2, "None");
	cls_TColgp_HArray2OfDir.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfDir::get_type_name, "None");
	cls_TColgp_HArray2OfDir.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfDir::get_type_descriptor, "None");
	cls_TColgp_HArray2OfDir.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfDir::*)() const ) &TColgp_HArray2OfDir::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray2OfXY.hxx
	py::class_<TColgp_HArray2OfXY, opencascade::handle<TColgp_HArray2OfXY>, TColgp_Array2OfXY, Standard_Transient> cls_TColgp_HArray2OfXY(mod, "TColgp_HArray2OfXY", "None");
	cls_TColgp_HArray2OfXY.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColgp_HArray2OfXY.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfXY::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColgp_HArray2OfXY.def(py::init<const TColgp_Array2OfXY &>(), py::arg("theOther"));
	cls_TColgp_HArray2OfXY.def("Array2", (const TColgp_Array2OfXY & (TColgp_HArray2OfXY::*)() const ) &TColgp_HArray2OfXY::Array2, "None");
	cls_TColgp_HArray2OfXY.def("ChangeArray2", (TColgp_Array2OfXY & (TColgp_HArray2OfXY::*)()) &TColgp_HArray2OfXY::ChangeArray2, "None");
	cls_TColgp_HArray2OfXY.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfXY::get_type_name, "None");
	cls_TColgp_HArray2OfXY.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfXY::get_type_descriptor, "None");
	cls_TColgp_HArray2OfXY.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfXY::*)() const ) &TColgp_HArray2OfXY::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray2OfDir2d.hxx
	py::class_<TColgp_HArray2OfDir2d, opencascade::handle<TColgp_HArray2OfDir2d>, TColgp_Array2OfDir2d, Standard_Transient> cls_TColgp_HArray2OfDir2d(mod, "TColgp_HArray2OfDir2d", "None");
	cls_TColgp_HArray2OfDir2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColgp_HArray2OfDir2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfDir2d::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColgp_HArray2OfDir2d.def(py::init<const TColgp_Array2OfDir2d &>(), py::arg("theOther"));
	cls_TColgp_HArray2OfDir2d.def("Array2", (const TColgp_Array2OfDir2d & (TColgp_HArray2OfDir2d::*)() const ) &TColgp_HArray2OfDir2d::Array2, "None");
	cls_TColgp_HArray2OfDir2d.def("ChangeArray2", (TColgp_Array2OfDir2d & (TColgp_HArray2OfDir2d::*)()) &TColgp_HArray2OfDir2d::ChangeArray2, "None");
	cls_TColgp_HArray2OfDir2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfDir2d::get_type_name, "None");
	cls_TColgp_HArray2OfDir2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfDir2d::get_type_descriptor, "None");
	cls_TColgp_HArray2OfDir2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfDir2d::*)() const ) &TColgp_HArray2OfDir2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray2OfVec2d.hxx
	py::class_<TColgp_HArray2OfVec2d, opencascade::handle<TColgp_HArray2OfVec2d>, TColgp_Array2OfVec2d, Standard_Transient> cls_TColgp_HArray2OfVec2d(mod, "TColgp_HArray2OfVec2d", "None");
	cls_TColgp_HArray2OfVec2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColgp_HArray2OfVec2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfVec2d::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColgp_HArray2OfVec2d.def(py::init<const TColgp_Array2OfVec2d &>(), py::arg("theOther"));
	cls_TColgp_HArray2OfVec2d.def("Array2", (const TColgp_Array2OfVec2d & (TColgp_HArray2OfVec2d::*)() const ) &TColgp_HArray2OfVec2d::Array2, "None");
	cls_TColgp_HArray2OfVec2d.def("ChangeArray2", (TColgp_Array2OfVec2d & (TColgp_HArray2OfVec2d::*)()) &TColgp_HArray2OfVec2d::ChangeArray2, "None");
	cls_TColgp_HArray2OfVec2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfVec2d::get_type_name, "None");
	cls_TColgp_HArray2OfVec2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfVec2d::get_type_descriptor, "None");
	cls_TColgp_HArray2OfVec2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfVec2d::*)() const ) &TColgp_HArray2OfVec2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray2OfLin2d.hxx
	py::class_<TColgp_HArray2OfLin2d, opencascade::handle<TColgp_HArray2OfLin2d>, TColgp_Array2OfLin2d, Standard_Transient> cls_TColgp_HArray2OfLin2d(mod, "TColgp_HArray2OfLin2d", "None");
	cls_TColgp_HArray2OfLin2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColgp_HArray2OfLin2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfLin2d::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColgp_HArray2OfLin2d.def(py::init<const TColgp_Array2OfLin2d &>(), py::arg("theOther"));
	cls_TColgp_HArray2OfLin2d.def("Array2", (const TColgp_Array2OfLin2d & (TColgp_HArray2OfLin2d::*)() const ) &TColgp_HArray2OfLin2d::Array2, "None");
	cls_TColgp_HArray2OfLin2d.def("ChangeArray2", (TColgp_Array2OfLin2d & (TColgp_HArray2OfLin2d::*)()) &TColgp_HArray2OfLin2d::ChangeArray2, "None");
	cls_TColgp_HArray2OfLin2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfLin2d::get_type_name, "None");
	cls_TColgp_HArray2OfLin2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfLin2d::get_type_descriptor, "None");
	cls_TColgp_HArray2OfLin2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfLin2d::*)() const ) &TColgp_HArray2OfLin2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HArray2OfCirc2d.hxx
	py::class_<TColgp_HArray2OfCirc2d, opencascade::handle<TColgp_HArray2OfCirc2d>, TColgp_Array2OfCirc2d, Standard_Transient> cls_TColgp_HArray2OfCirc2d(mod, "TColgp_HArray2OfCirc2d", "None");
	cls_TColgp_HArray2OfCirc2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColgp_HArray2OfCirc2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfCirc2d::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColgp_HArray2OfCirc2d.def(py::init<const TColgp_Array2OfCirc2d &>(), py::arg("theOther"));
	cls_TColgp_HArray2OfCirc2d.def("Array2", (const TColgp_Array2OfCirc2d & (TColgp_HArray2OfCirc2d::*)() const ) &TColgp_HArray2OfCirc2d::Array2, "None");
	cls_TColgp_HArray2OfCirc2d.def("ChangeArray2", (TColgp_Array2OfCirc2d & (TColgp_HArray2OfCirc2d::*)()) &TColgp_HArray2OfCirc2d::ChangeArray2, "None");
	cls_TColgp_HArray2OfCirc2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfCirc2d::get_type_name, "None");
	cls_TColgp_HArray2OfCirc2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfCirc2d::get_type_descriptor, "None");
	cls_TColgp_HArray2OfCirc2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfCirc2d::*)() const ) &TColgp_HArray2OfCirc2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HSequenceOfDir.hxx
	py::class_<TColgp_HSequenceOfDir, opencascade::handle<TColgp_HSequenceOfDir>, TColgp_SequenceOfDir, Standard_Transient> cls_TColgp_HSequenceOfDir(mod, "TColgp_HSequenceOfDir", "None");
	cls_TColgp_HSequenceOfDir.def(py::init<>());
	cls_TColgp_HSequenceOfDir.def(py::init<const TColgp_SequenceOfDir &>(), py::arg("theOther"));
	cls_TColgp_HSequenceOfDir.def("Sequence", (const TColgp_SequenceOfDir & (TColgp_HSequenceOfDir::*)() const ) &TColgp_HSequenceOfDir::Sequence, "None");
	cls_TColgp_HSequenceOfDir.def("Append", (void (TColgp_HSequenceOfDir::*)(const TColgp_SequenceOfDir::value_type &)) &TColgp_HSequenceOfDir::Append, "None", py::arg("theItem"));
	cls_TColgp_HSequenceOfDir.def("Append", (void (TColgp_HSequenceOfDir::*)(TColgp_SequenceOfDir &)) &TColgp_HSequenceOfDir::Append, "None", py::arg("theSequence"));
	cls_TColgp_HSequenceOfDir.def("ChangeSequence", (TColgp_SequenceOfDir & (TColgp_HSequenceOfDir::*)()) &TColgp_HSequenceOfDir::ChangeSequence, "None");
	cls_TColgp_HSequenceOfDir.def_static("get_type_name_", (const char * (*)()) &TColgp_HSequenceOfDir::get_type_name, "None");
	cls_TColgp_HSequenceOfDir.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HSequenceOfDir::get_type_descriptor, "None");
	cls_TColgp_HSequenceOfDir.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HSequenceOfDir::*)() const ) &TColgp_HSequenceOfDir::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HSequenceOfDir2d.hxx
	py::class_<TColgp_HSequenceOfDir2d, opencascade::handle<TColgp_HSequenceOfDir2d>, TColgp_SequenceOfDir2d, Standard_Transient> cls_TColgp_HSequenceOfDir2d(mod, "TColgp_HSequenceOfDir2d", "None");
	cls_TColgp_HSequenceOfDir2d.def(py::init<>());
	cls_TColgp_HSequenceOfDir2d.def(py::init<const TColgp_SequenceOfDir2d &>(), py::arg("theOther"));
	cls_TColgp_HSequenceOfDir2d.def("Sequence", (const TColgp_SequenceOfDir2d & (TColgp_HSequenceOfDir2d::*)() const ) &TColgp_HSequenceOfDir2d::Sequence, "None");
	cls_TColgp_HSequenceOfDir2d.def("Append", (void (TColgp_HSequenceOfDir2d::*)(const TColgp_SequenceOfDir2d::value_type &)) &TColgp_HSequenceOfDir2d::Append, "None", py::arg("theItem"));
	cls_TColgp_HSequenceOfDir2d.def("Append", (void (TColgp_HSequenceOfDir2d::*)(TColgp_SequenceOfDir2d &)) &TColgp_HSequenceOfDir2d::Append, "None", py::arg("theSequence"));
	cls_TColgp_HSequenceOfDir2d.def("ChangeSequence", (TColgp_SequenceOfDir2d & (TColgp_HSequenceOfDir2d::*)()) &TColgp_HSequenceOfDir2d::ChangeSequence, "None");
	cls_TColgp_HSequenceOfDir2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HSequenceOfDir2d::get_type_name, "None");
	cls_TColgp_HSequenceOfDir2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HSequenceOfDir2d::get_type_descriptor, "None");
	cls_TColgp_HSequenceOfDir2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HSequenceOfDir2d::*)() const ) &TColgp_HSequenceOfDir2d::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColgp_HSequenceOfVec2d.hxx
	py::class_<TColgp_HSequenceOfVec2d, opencascade::handle<TColgp_HSequenceOfVec2d>, TColgp_SequenceOfVec2d, Standard_Transient> cls_TColgp_HSequenceOfVec2d(mod, "TColgp_HSequenceOfVec2d", "None");
	cls_TColgp_HSequenceOfVec2d.def(py::init<>());
	cls_TColgp_HSequenceOfVec2d.def(py::init<const TColgp_SequenceOfVec2d &>(), py::arg("theOther"));
	cls_TColgp_HSequenceOfVec2d.def("Sequence", (const TColgp_SequenceOfVec2d & (TColgp_HSequenceOfVec2d::*)() const ) &TColgp_HSequenceOfVec2d::Sequence, "None");
	cls_TColgp_HSequenceOfVec2d.def("Append", (void (TColgp_HSequenceOfVec2d::*)(const TColgp_SequenceOfVec2d::value_type &)) &TColgp_HSequenceOfVec2d::Append, "None", py::arg("theItem"));
	cls_TColgp_HSequenceOfVec2d.def("Append", (void (TColgp_HSequenceOfVec2d::*)(TColgp_SequenceOfVec2d &)) &TColgp_HSequenceOfVec2d::Append, "None", py::arg("theSequence"));
	cls_TColgp_HSequenceOfVec2d.def("ChangeSequence", (TColgp_SequenceOfVec2d & (TColgp_HSequenceOfVec2d::*)()) &TColgp_HSequenceOfVec2d::ChangeSequence, "None");
	cls_TColgp_HSequenceOfVec2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HSequenceOfVec2d::get_type_name, "None");
	cls_TColgp_HSequenceOfVec2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HSequenceOfVec2d::get_type_descriptor, "None");
	cls_TColgp_HSequenceOfVec2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HSequenceOfVec2d::*)() const ) &TColgp_HSequenceOfVec2d::DynamicType, "None");


}
