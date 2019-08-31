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
#include <NCollection_Array1.hxx>
#include <gp_Pnt2d.hxx>
#include <TColgp_Array1OfPnt2d.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <TColgp_HArray1OfPnt2d.hxx>
#include <Standard_Type.hxx>
#include <gp_Pnt.hxx>
#include <TColgp_Array1OfPnt.hxx>
#include <NCollection_Array2.hxx>
#include <TColgp_Array2OfPnt.hxx>
#include <TColgp_HArray2OfPnt.hxx>
#include <TColgp_Array2OfPnt2d.hxx>
#include <TColgp_HArray2OfPnt2d.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <NCollection_Sequence.hxx>
#include <TColgp_SequenceOfPnt.hxx>
#include <TColgp_HSequenceOfPnt.hxx>
#include <gp_Dir.hxx>
#include <TColgp_Array1OfDir.hxx>
#include <TColgp_HArray1OfDir.hxx>
#include <gp_Vec.hxx>
#include <TColgp_Array1OfVec.hxx>
#include <TColgp_HArray1OfVec.hxx>
#include <gp_Vec2d.hxx>
#include <TColgp_Array1OfVec2d.hxx>
#include <TColgp_HArray1OfVec2d.hxx>
#include <TColgp_SequenceOfArray1OfPnt2d.hxx>
#include <gp_XYZ.hxx>
#include <TColgp_Array2OfXYZ.hxx>
#include <TColgp_HArray2OfXYZ.hxx>
#include <TColgp_Array1OfXYZ.hxx>
#include <gp_XY.hxx>
#include <TColgp_SequenceOfXY.hxx>
#include <TColgp_SequenceOfXYZ.hxx>
#include <TColgp_SequenceOfPnt2d.hxx>
#include <gp_Ax1.hxx>
#include <TColgp_SequenceOfAx1.hxx>
#include <TColgp_HSequenceOfXY.hxx>
#include <TColgp_Array2OfVec.hxx>
#include <TColgp_Array1OfXY.hxx>
#include <gp_Circ2d.hxx>
#include <TColgp_Array1OfCirc2d.hxx>
#include <gp_Lin2d.hxx>
#include <TColgp_Array1OfLin2d.hxx>
#include <TColgp_SequenceOfVec.hxx>
#include <TColgp_HArray1OfXYZ.hxx>
#include <TColgp_HArray1OfXY.hxx>
#include <TColgp_HSequenceOfXYZ.hxx>
#include <gp_Dir2d.hxx>
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
#include <bind_NCollection_Array1.hxx>
#include <bind_NCollection_Array2.hxx>
#include <bind_NCollection_Sequence.hxx>

PYBIND11_MODULE(TColgp, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.gp");
py::module::import("OCCT.Standard");

// TYPEDEF: TCOLGP_ARRAY1OFPNT2D
bind_NCollection_Array1<gp_Pnt2d>(mod, "TColgp_Array1OfPnt2d", py::module_local(false));

// CLASS: TCOLGP_HARRAY1OFPNT2D
py::class_<TColgp_HArray1OfPnt2d, opencascade::handle<TColgp_HArray1OfPnt2d>, Standard_Transient> cls_TColgp_HArray1OfPnt2d(mod, "TColgp_HArray1OfPnt2d", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HArray1OfPnt2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TColgp_HArray1OfPnt2d.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfPnt2d::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TColgp_HArray1OfPnt2d.def(py::init<const TColgp_Array1OfPnt2d &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HArray1OfPnt2d.def_static("operator new_", (void * (*)(size_t)) &TColgp_HArray1OfPnt2d::operator new, "None", py::arg("theSize"));
// cls_TColgp_HArray1OfPnt2d.def_static("operator delete_", (void (*)(void *)) &TColgp_HArray1OfPnt2d::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HArray1OfPnt2d.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HArray1OfPnt2d::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HArray1OfPnt2d.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HArray1OfPnt2d::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HArray1OfPnt2d.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HArray1OfPnt2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HArray1OfPnt2d.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HArray1OfPnt2d::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HArray1OfPnt2d.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray1OfPnt2d::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HArray1OfPnt2d.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray1OfPnt2d::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HArray1OfPnt2d.def("Array1", (const TColgp_Array1OfPnt2d & (TColgp_HArray1OfPnt2d::*)() const) &TColgp_HArray1OfPnt2d::Array1, "None");
cls_TColgp_HArray1OfPnt2d.def("ChangeArray1", (TColgp_Array1OfPnt2d & (TColgp_HArray1OfPnt2d::*)()) &TColgp_HArray1OfPnt2d::ChangeArray1, "None");
cls_TColgp_HArray1OfPnt2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfPnt2d::get_type_name, "None");
cls_TColgp_HArray1OfPnt2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfPnt2d::get_type_descriptor, "None");
cls_TColgp_HArray1OfPnt2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfPnt2d::*)() const) &TColgp_HArray1OfPnt2d::DynamicType, "None");

// TYPEDEF: TCOLGP_ARRAY1OFPNT
bind_NCollection_Array1<gp_Pnt>(mod, "TColgp_Array1OfPnt", py::module_local(false));

// TYPEDEF: TCOLGP_ARRAY2OFPNT
bind_NCollection_Array2<gp_Pnt>(mod, "TColgp_Array2OfPnt", py::module_local(false));

// CLASS: TCOLGP_HARRAY2OFPNT
py::class_<TColgp_HArray2OfPnt, opencascade::handle<TColgp_HArray2OfPnt>, Standard_Transient> cls_TColgp_HArray2OfPnt(mod, "TColgp_HArray2OfPnt", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HArray2OfPnt.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_TColgp_HArray2OfPnt.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfPnt::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_TColgp_HArray2OfPnt.def(py::init<const TColgp_Array2OfPnt &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HArray2OfPnt.def_static("operator new_", (void * (*)(size_t)) &TColgp_HArray2OfPnt::operator new, "None", py::arg("theSize"));
// cls_TColgp_HArray2OfPnt.def_static("operator delete_", (void (*)(void *)) &TColgp_HArray2OfPnt::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HArray2OfPnt.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HArray2OfPnt::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HArray2OfPnt.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HArray2OfPnt::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HArray2OfPnt.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HArray2OfPnt::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HArray2OfPnt.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HArray2OfPnt::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HArray2OfPnt.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray2OfPnt::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HArray2OfPnt.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray2OfPnt::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HArray2OfPnt.def("Array2", (const TColgp_Array2OfPnt & (TColgp_HArray2OfPnt::*)() const) &TColgp_HArray2OfPnt::Array2, "None");
cls_TColgp_HArray2OfPnt.def("ChangeArray2", (TColgp_Array2OfPnt & (TColgp_HArray2OfPnt::*)()) &TColgp_HArray2OfPnt::ChangeArray2, "None");
cls_TColgp_HArray2OfPnt.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfPnt::get_type_name, "None");
cls_TColgp_HArray2OfPnt.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfPnt::get_type_descriptor, "None");
cls_TColgp_HArray2OfPnt.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfPnt::*)() const) &TColgp_HArray2OfPnt::DynamicType, "None");

// TYPEDEF: TCOLGP_ARRAY2OFPNT2D
bind_NCollection_Array2<gp_Pnt2d>(mod, "TColgp_Array2OfPnt2d", py::module_local(false));

// CLASS: TCOLGP_HARRAY2OFPNT2D
py::class_<TColgp_HArray2OfPnt2d, opencascade::handle<TColgp_HArray2OfPnt2d>, Standard_Transient> cls_TColgp_HArray2OfPnt2d(mod, "TColgp_HArray2OfPnt2d", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HArray2OfPnt2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_TColgp_HArray2OfPnt2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfPnt2d::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_TColgp_HArray2OfPnt2d.def(py::init<const TColgp_Array2OfPnt2d &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HArray2OfPnt2d.def_static("operator new_", (void * (*)(size_t)) &TColgp_HArray2OfPnt2d::operator new, "None", py::arg("theSize"));
// cls_TColgp_HArray2OfPnt2d.def_static("operator delete_", (void (*)(void *)) &TColgp_HArray2OfPnt2d::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HArray2OfPnt2d.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HArray2OfPnt2d::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HArray2OfPnt2d.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HArray2OfPnt2d::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HArray2OfPnt2d.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HArray2OfPnt2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HArray2OfPnt2d.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HArray2OfPnt2d::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HArray2OfPnt2d.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray2OfPnt2d::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HArray2OfPnt2d.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray2OfPnt2d::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HArray2OfPnt2d.def("Array2", (const TColgp_Array2OfPnt2d & (TColgp_HArray2OfPnt2d::*)() const) &TColgp_HArray2OfPnt2d::Array2, "None");
cls_TColgp_HArray2OfPnt2d.def("ChangeArray2", (TColgp_Array2OfPnt2d & (TColgp_HArray2OfPnt2d::*)()) &TColgp_HArray2OfPnt2d::ChangeArray2, "None");
cls_TColgp_HArray2OfPnt2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfPnt2d::get_type_name, "None");
cls_TColgp_HArray2OfPnt2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfPnt2d::get_type_descriptor, "None");
cls_TColgp_HArray2OfPnt2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfPnt2d::*)() const) &TColgp_HArray2OfPnt2d::DynamicType, "None");

// CLASS: TCOLGP_HARRAY1OFPNT
py::class_<TColgp_HArray1OfPnt, opencascade::handle<TColgp_HArray1OfPnt>, Standard_Transient> cls_TColgp_HArray1OfPnt(mod, "TColgp_HArray1OfPnt", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HArray1OfPnt.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TColgp_HArray1OfPnt.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfPnt::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TColgp_HArray1OfPnt.def(py::init<const TColgp_Array1OfPnt &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HArray1OfPnt.def_static("operator new_", (void * (*)(size_t)) &TColgp_HArray1OfPnt::operator new, "None", py::arg("theSize"));
// cls_TColgp_HArray1OfPnt.def_static("operator delete_", (void (*)(void *)) &TColgp_HArray1OfPnt::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HArray1OfPnt.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HArray1OfPnt::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HArray1OfPnt.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HArray1OfPnt::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HArray1OfPnt.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HArray1OfPnt::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HArray1OfPnt.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HArray1OfPnt::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HArray1OfPnt.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray1OfPnt::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HArray1OfPnt.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray1OfPnt::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HArray1OfPnt.def("Array1", (const TColgp_Array1OfPnt & (TColgp_HArray1OfPnt::*)() const) &TColgp_HArray1OfPnt::Array1, "None");
cls_TColgp_HArray1OfPnt.def("ChangeArray1", (TColgp_Array1OfPnt & (TColgp_HArray1OfPnt::*)()) &TColgp_HArray1OfPnt::ChangeArray1, "None");
cls_TColgp_HArray1OfPnt.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfPnt::get_type_name, "None");
cls_TColgp_HArray1OfPnt.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfPnt::get_type_descriptor, "None");
cls_TColgp_HArray1OfPnt.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfPnt::*)() const) &TColgp_HArray1OfPnt::DynamicType, "None");

// TYPEDEF: TCOLGP_SEQUENCEOFPNT
bind_NCollection_Sequence<gp_Pnt>(mod, "TColgp_SequenceOfPnt", py::module_local(false));

// CLASS: TCOLGP_HSEQUENCEOFPNT
py::class_<TColgp_HSequenceOfPnt, opencascade::handle<TColgp_HSequenceOfPnt>, Standard_Transient> cls_TColgp_HSequenceOfPnt(mod, "TColgp_HSequenceOfPnt", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HSequenceOfPnt.def(py::init<>());
cls_TColgp_HSequenceOfPnt.def(py::init<const TColgp_SequenceOfPnt &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HSequenceOfPnt.def_static("operator new_", (void * (*)(size_t)) &TColgp_HSequenceOfPnt::operator new, "None", py::arg("theSize"));
// cls_TColgp_HSequenceOfPnt.def_static("operator delete_", (void (*)(void *)) &TColgp_HSequenceOfPnt::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HSequenceOfPnt.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HSequenceOfPnt::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HSequenceOfPnt.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HSequenceOfPnt::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HSequenceOfPnt.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HSequenceOfPnt::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HSequenceOfPnt.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HSequenceOfPnt::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HSequenceOfPnt.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HSequenceOfPnt::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HSequenceOfPnt.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HSequenceOfPnt::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HSequenceOfPnt.def("Sequence", (const TColgp_SequenceOfPnt & (TColgp_HSequenceOfPnt::*)() const) &TColgp_HSequenceOfPnt::Sequence, "None");
cls_TColgp_HSequenceOfPnt.def("Append", (void (TColgp_HSequenceOfPnt::*)(const TColgp_SequenceOfPnt::value_type &)) &TColgp_HSequenceOfPnt::Append, "None", py::arg("theItem"));
cls_TColgp_HSequenceOfPnt.def("Append", (void (TColgp_HSequenceOfPnt::*)(TColgp_SequenceOfPnt &)) &TColgp_HSequenceOfPnt::Append, "None", py::arg("theSequence"));
cls_TColgp_HSequenceOfPnt.def("ChangeSequence", (TColgp_SequenceOfPnt & (TColgp_HSequenceOfPnt::*)()) &TColgp_HSequenceOfPnt::ChangeSequence, "None");
cls_TColgp_HSequenceOfPnt.def_static("get_type_name_", (const char * (*)()) &TColgp_HSequenceOfPnt::get_type_name, "None");
cls_TColgp_HSequenceOfPnt.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HSequenceOfPnt::get_type_descriptor, "None");
cls_TColgp_HSequenceOfPnt.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HSequenceOfPnt::*)() const) &TColgp_HSequenceOfPnt::DynamicType, "None");

// TYPEDEF: TCOLGP_ARRAY1OFDIR
bind_NCollection_Array1<gp_Dir>(mod, "TColgp_Array1OfDir", py::module_local(false));

// CLASS: TCOLGP_HARRAY1OFDIR
py::class_<TColgp_HArray1OfDir, opencascade::handle<TColgp_HArray1OfDir>, Standard_Transient> cls_TColgp_HArray1OfDir(mod, "TColgp_HArray1OfDir", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HArray1OfDir.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TColgp_HArray1OfDir.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfDir::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TColgp_HArray1OfDir.def(py::init<const TColgp_Array1OfDir &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HArray1OfDir.def_static("operator new_", (void * (*)(size_t)) &TColgp_HArray1OfDir::operator new, "None", py::arg("theSize"));
// cls_TColgp_HArray1OfDir.def_static("operator delete_", (void (*)(void *)) &TColgp_HArray1OfDir::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HArray1OfDir.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HArray1OfDir::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HArray1OfDir.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HArray1OfDir::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HArray1OfDir.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HArray1OfDir::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HArray1OfDir.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HArray1OfDir::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HArray1OfDir.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray1OfDir::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HArray1OfDir.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray1OfDir::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HArray1OfDir.def("Array1", (const TColgp_Array1OfDir & (TColgp_HArray1OfDir::*)() const) &TColgp_HArray1OfDir::Array1, "None");
cls_TColgp_HArray1OfDir.def("ChangeArray1", (TColgp_Array1OfDir & (TColgp_HArray1OfDir::*)()) &TColgp_HArray1OfDir::ChangeArray1, "None");
cls_TColgp_HArray1OfDir.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfDir::get_type_name, "None");
cls_TColgp_HArray1OfDir.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfDir::get_type_descriptor, "None");
cls_TColgp_HArray1OfDir.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfDir::*)() const) &TColgp_HArray1OfDir::DynamicType, "None");

// TYPEDEF: TCOLGP_ARRAY1OFVEC
bind_NCollection_Array1<gp_Vec>(mod, "TColgp_Array1OfVec", py::module_local(false));

// CLASS: TCOLGP_HARRAY1OFVEC
py::class_<TColgp_HArray1OfVec, opencascade::handle<TColgp_HArray1OfVec>, Standard_Transient> cls_TColgp_HArray1OfVec(mod, "TColgp_HArray1OfVec", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HArray1OfVec.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TColgp_HArray1OfVec.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfVec::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TColgp_HArray1OfVec.def(py::init<const TColgp_Array1OfVec &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HArray1OfVec.def_static("operator new_", (void * (*)(size_t)) &TColgp_HArray1OfVec::operator new, "None", py::arg("theSize"));
// cls_TColgp_HArray1OfVec.def_static("operator delete_", (void (*)(void *)) &TColgp_HArray1OfVec::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HArray1OfVec.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HArray1OfVec::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HArray1OfVec.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HArray1OfVec::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HArray1OfVec.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HArray1OfVec::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HArray1OfVec.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HArray1OfVec::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HArray1OfVec.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray1OfVec::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HArray1OfVec.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray1OfVec::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HArray1OfVec.def("Array1", (const TColgp_Array1OfVec & (TColgp_HArray1OfVec::*)() const) &TColgp_HArray1OfVec::Array1, "None");
cls_TColgp_HArray1OfVec.def("ChangeArray1", (TColgp_Array1OfVec & (TColgp_HArray1OfVec::*)()) &TColgp_HArray1OfVec::ChangeArray1, "None");
cls_TColgp_HArray1OfVec.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfVec::get_type_name, "None");
cls_TColgp_HArray1OfVec.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfVec::get_type_descriptor, "None");
cls_TColgp_HArray1OfVec.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfVec::*)() const) &TColgp_HArray1OfVec::DynamicType, "None");

// TYPEDEF: TCOLGP_ARRAY1OFVEC2D
bind_NCollection_Array1<gp_Vec2d>(mod, "TColgp_Array1OfVec2d", py::module_local(false));

// CLASS: TCOLGP_HARRAY1OFVEC2D
py::class_<TColgp_HArray1OfVec2d, opencascade::handle<TColgp_HArray1OfVec2d>, Standard_Transient> cls_TColgp_HArray1OfVec2d(mod, "TColgp_HArray1OfVec2d", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HArray1OfVec2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TColgp_HArray1OfVec2d.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfVec2d::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TColgp_HArray1OfVec2d.def(py::init<const TColgp_Array1OfVec2d &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HArray1OfVec2d.def_static("operator new_", (void * (*)(size_t)) &TColgp_HArray1OfVec2d::operator new, "None", py::arg("theSize"));
// cls_TColgp_HArray1OfVec2d.def_static("operator delete_", (void (*)(void *)) &TColgp_HArray1OfVec2d::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HArray1OfVec2d.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HArray1OfVec2d::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HArray1OfVec2d.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HArray1OfVec2d::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HArray1OfVec2d.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HArray1OfVec2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HArray1OfVec2d.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HArray1OfVec2d::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HArray1OfVec2d.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray1OfVec2d::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HArray1OfVec2d.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray1OfVec2d::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HArray1OfVec2d.def("Array1", (const TColgp_Array1OfVec2d & (TColgp_HArray1OfVec2d::*)() const) &TColgp_HArray1OfVec2d::Array1, "None");
cls_TColgp_HArray1OfVec2d.def("ChangeArray1", (TColgp_Array1OfVec2d & (TColgp_HArray1OfVec2d::*)()) &TColgp_HArray1OfVec2d::ChangeArray1, "None");
cls_TColgp_HArray1OfVec2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfVec2d::get_type_name, "None");
cls_TColgp_HArray1OfVec2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfVec2d::get_type_descriptor, "None");
cls_TColgp_HArray1OfVec2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfVec2d::*)() const) &TColgp_HArray1OfVec2d::DynamicType, "None");

// TYPEDEF: TCOLGP_SEQUENCEOFARRAY1OFPNT2D
bind_NCollection_Sequence<opencascade::handle<TColgp_HArray1OfPnt2d> >(mod, "TColgp_SequenceOfArray1OfPnt2d", py::module_local(false));

// TYPEDEF: TCOLGP_ARRAY2OFXYZ
bind_NCollection_Array2<gp_XYZ>(mod, "TColgp_Array2OfXYZ", py::module_local(false));

// CLASS: TCOLGP_HARRAY2OFXYZ
py::class_<TColgp_HArray2OfXYZ, opencascade::handle<TColgp_HArray2OfXYZ>, Standard_Transient> cls_TColgp_HArray2OfXYZ(mod, "TColgp_HArray2OfXYZ", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HArray2OfXYZ.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_TColgp_HArray2OfXYZ.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfXYZ::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_TColgp_HArray2OfXYZ.def(py::init<const TColgp_Array2OfXYZ &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HArray2OfXYZ.def_static("operator new_", (void * (*)(size_t)) &TColgp_HArray2OfXYZ::operator new, "None", py::arg("theSize"));
// cls_TColgp_HArray2OfXYZ.def_static("operator delete_", (void (*)(void *)) &TColgp_HArray2OfXYZ::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HArray2OfXYZ.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HArray2OfXYZ::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HArray2OfXYZ.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HArray2OfXYZ::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HArray2OfXYZ.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HArray2OfXYZ::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HArray2OfXYZ.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HArray2OfXYZ::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HArray2OfXYZ.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray2OfXYZ::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HArray2OfXYZ.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray2OfXYZ::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HArray2OfXYZ.def("Array2", (const TColgp_Array2OfXYZ & (TColgp_HArray2OfXYZ::*)() const) &TColgp_HArray2OfXYZ::Array2, "None");
cls_TColgp_HArray2OfXYZ.def("ChangeArray2", (TColgp_Array2OfXYZ & (TColgp_HArray2OfXYZ::*)()) &TColgp_HArray2OfXYZ::ChangeArray2, "None");
cls_TColgp_HArray2OfXYZ.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfXYZ::get_type_name, "None");
cls_TColgp_HArray2OfXYZ.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfXYZ::get_type_descriptor, "None");
cls_TColgp_HArray2OfXYZ.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfXYZ::*)() const) &TColgp_HArray2OfXYZ::DynamicType, "None");

// TYPEDEF: TCOLGP_ARRAY1OFXYZ
bind_NCollection_Array1<gp_XYZ>(mod, "TColgp_Array1OfXYZ", py::module_local(false));

// TYPEDEF: TCOLGP_SEQUENCEOFXY
bind_NCollection_Sequence<gp_XY>(mod, "TColgp_SequenceOfXY", py::module_local(false));

// TYPEDEF: TCOLGP_SEQUENCEOFXYZ
bind_NCollection_Sequence<gp_XYZ>(mod, "TColgp_SequenceOfXYZ", py::module_local(false));

// TYPEDEF: TCOLGP_SEQUENCEOFPNT2D
bind_NCollection_Sequence<gp_Pnt2d>(mod, "TColgp_SequenceOfPnt2d", py::module_local(false));

// TYPEDEF: TCOLGP_SEQUENCEOFAX1
bind_NCollection_Sequence<gp_Ax1>(mod, "TColgp_SequenceOfAx1", py::module_local(false));

// CLASS: TCOLGP_HSEQUENCEOFXY
py::class_<TColgp_HSequenceOfXY, opencascade::handle<TColgp_HSequenceOfXY>, Standard_Transient> cls_TColgp_HSequenceOfXY(mod, "TColgp_HSequenceOfXY", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HSequenceOfXY.def(py::init<>());
cls_TColgp_HSequenceOfXY.def(py::init<const TColgp_SequenceOfXY &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HSequenceOfXY.def_static("operator new_", (void * (*)(size_t)) &TColgp_HSequenceOfXY::operator new, "None", py::arg("theSize"));
// cls_TColgp_HSequenceOfXY.def_static("operator delete_", (void (*)(void *)) &TColgp_HSequenceOfXY::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HSequenceOfXY.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HSequenceOfXY::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HSequenceOfXY.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HSequenceOfXY::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HSequenceOfXY.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HSequenceOfXY::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HSequenceOfXY.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HSequenceOfXY::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HSequenceOfXY.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HSequenceOfXY::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HSequenceOfXY.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HSequenceOfXY::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HSequenceOfXY.def("Sequence", (const TColgp_SequenceOfXY & (TColgp_HSequenceOfXY::*)() const) &TColgp_HSequenceOfXY::Sequence, "None");
cls_TColgp_HSequenceOfXY.def("Append", (void (TColgp_HSequenceOfXY::*)(const TColgp_SequenceOfXY::value_type &)) &TColgp_HSequenceOfXY::Append, "None", py::arg("theItem"));
cls_TColgp_HSequenceOfXY.def("Append", (void (TColgp_HSequenceOfXY::*)(TColgp_SequenceOfXY &)) &TColgp_HSequenceOfXY::Append, "None", py::arg("theSequence"));
cls_TColgp_HSequenceOfXY.def("ChangeSequence", (TColgp_SequenceOfXY & (TColgp_HSequenceOfXY::*)()) &TColgp_HSequenceOfXY::ChangeSequence, "None");
cls_TColgp_HSequenceOfXY.def_static("get_type_name_", (const char * (*)()) &TColgp_HSequenceOfXY::get_type_name, "None");
cls_TColgp_HSequenceOfXY.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HSequenceOfXY::get_type_descriptor, "None");
cls_TColgp_HSequenceOfXY.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HSequenceOfXY::*)() const) &TColgp_HSequenceOfXY::DynamicType, "None");

// TYPEDEF: TCOLGP_ARRAY2OFVEC
bind_NCollection_Array2<gp_Vec>(mod, "TColgp_Array2OfVec", py::module_local(false));

// TYPEDEF: TCOLGP_ARRAY1OFXY
bind_NCollection_Array1<gp_XY>(mod, "TColgp_Array1OfXY", py::module_local(false));

// TYPEDEF: TCOLGP_ARRAY1OFCIRC2D
bind_NCollection_Array1<gp_Circ2d>(mod, "TColgp_Array1OfCirc2d", py::module_local(false));

// TYPEDEF: TCOLGP_ARRAY1OFLIN2D
bind_NCollection_Array1<gp_Lin2d>(mod, "TColgp_Array1OfLin2d", py::module_local(false));

// TYPEDEF: TCOLGP_SEQUENCEOFVEC
bind_NCollection_Sequence<gp_Vec>(mod, "TColgp_SequenceOfVec", py::module_local(false));

// CLASS: TCOLGP_HARRAY1OFXYZ
py::class_<TColgp_HArray1OfXYZ, opencascade::handle<TColgp_HArray1OfXYZ>, Standard_Transient> cls_TColgp_HArray1OfXYZ(mod, "TColgp_HArray1OfXYZ", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HArray1OfXYZ.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TColgp_HArray1OfXYZ.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfXYZ::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TColgp_HArray1OfXYZ.def(py::init<const TColgp_Array1OfXYZ &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HArray1OfXYZ.def_static("operator new_", (void * (*)(size_t)) &TColgp_HArray1OfXYZ::operator new, "None", py::arg("theSize"));
// cls_TColgp_HArray1OfXYZ.def_static("operator delete_", (void (*)(void *)) &TColgp_HArray1OfXYZ::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HArray1OfXYZ.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HArray1OfXYZ::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HArray1OfXYZ.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HArray1OfXYZ::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HArray1OfXYZ.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HArray1OfXYZ::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HArray1OfXYZ.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HArray1OfXYZ::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HArray1OfXYZ.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray1OfXYZ::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HArray1OfXYZ.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray1OfXYZ::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HArray1OfXYZ.def("Array1", (const TColgp_Array1OfXYZ & (TColgp_HArray1OfXYZ::*)() const) &TColgp_HArray1OfXYZ::Array1, "None");
cls_TColgp_HArray1OfXYZ.def("ChangeArray1", (TColgp_Array1OfXYZ & (TColgp_HArray1OfXYZ::*)()) &TColgp_HArray1OfXYZ::ChangeArray1, "None");
cls_TColgp_HArray1OfXYZ.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfXYZ::get_type_name, "None");
cls_TColgp_HArray1OfXYZ.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfXYZ::get_type_descriptor, "None");
cls_TColgp_HArray1OfXYZ.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfXYZ::*)() const) &TColgp_HArray1OfXYZ::DynamicType, "None");

// CLASS: TCOLGP_HARRAY1OFXY
py::class_<TColgp_HArray1OfXY, opencascade::handle<TColgp_HArray1OfXY>, Standard_Transient> cls_TColgp_HArray1OfXY(mod, "TColgp_HArray1OfXY", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HArray1OfXY.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TColgp_HArray1OfXY.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfXY::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TColgp_HArray1OfXY.def(py::init<const TColgp_Array1OfXY &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HArray1OfXY.def_static("operator new_", (void * (*)(size_t)) &TColgp_HArray1OfXY::operator new, "None", py::arg("theSize"));
// cls_TColgp_HArray1OfXY.def_static("operator delete_", (void (*)(void *)) &TColgp_HArray1OfXY::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HArray1OfXY.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HArray1OfXY::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HArray1OfXY.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HArray1OfXY::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HArray1OfXY.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HArray1OfXY::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HArray1OfXY.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HArray1OfXY::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HArray1OfXY.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray1OfXY::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HArray1OfXY.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray1OfXY::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HArray1OfXY.def("Array1", (const TColgp_Array1OfXY & (TColgp_HArray1OfXY::*)() const) &TColgp_HArray1OfXY::Array1, "None");
cls_TColgp_HArray1OfXY.def("ChangeArray1", (TColgp_Array1OfXY & (TColgp_HArray1OfXY::*)()) &TColgp_HArray1OfXY::ChangeArray1, "None");
cls_TColgp_HArray1OfXY.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfXY::get_type_name, "None");
cls_TColgp_HArray1OfXY.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfXY::get_type_descriptor, "None");
cls_TColgp_HArray1OfXY.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfXY::*)() const) &TColgp_HArray1OfXY::DynamicType, "None");

// CLASS: TCOLGP_HSEQUENCEOFXYZ
py::class_<TColgp_HSequenceOfXYZ, opencascade::handle<TColgp_HSequenceOfXYZ>, Standard_Transient> cls_TColgp_HSequenceOfXYZ(mod, "TColgp_HSequenceOfXYZ", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HSequenceOfXYZ.def(py::init<>());
cls_TColgp_HSequenceOfXYZ.def(py::init<const TColgp_SequenceOfXYZ &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HSequenceOfXYZ.def_static("operator new_", (void * (*)(size_t)) &TColgp_HSequenceOfXYZ::operator new, "None", py::arg("theSize"));
// cls_TColgp_HSequenceOfXYZ.def_static("operator delete_", (void (*)(void *)) &TColgp_HSequenceOfXYZ::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HSequenceOfXYZ.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HSequenceOfXYZ::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HSequenceOfXYZ.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HSequenceOfXYZ::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HSequenceOfXYZ.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HSequenceOfXYZ::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HSequenceOfXYZ.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HSequenceOfXYZ::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HSequenceOfXYZ.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HSequenceOfXYZ::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HSequenceOfXYZ.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HSequenceOfXYZ::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HSequenceOfXYZ.def("Sequence", (const TColgp_SequenceOfXYZ & (TColgp_HSequenceOfXYZ::*)() const) &TColgp_HSequenceOfXYZ::Sequence, "None");
cls_TColgp_HSequenceOfXYZ.def("Append", (void (TColgp_HSequenceOfXYZ::*)(const TColgp_SequenceOfXYZ::value_type &)) &TColgp_HSequenceOfXYZ::Append, "None", py::arg("theItem"));
cls_TColgp_HSequenceOfXYZ.def("Append", (void (TColgp_HSequenceOfXYZ::*)(TColgp_SequenceOfXYZ &)) &TColgp_HSequenceOfXYZ::Append, "None", py::arg("theSequence"));
cls_TColgp_HSequenceOfXYZ.def("ChangeSequence", (TColgp_SequenceOfXYZ & (TColgp_HSequenceOfXYZ::*)()) &TColgp_HSequenceOfXYZ::ChangeSequence, "None");
cls_TColgp_HSequenceOfXYZ.def_static("get_type_name_", (const char * (*)()) &TColgp_HSequenceOfXYZ::get_type_name, "None");
cls_TColgp_HSequenceOfXYZ.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HSequenceOfXYZ::get_type_descriptor, "None");
cls_TColgp_HSequenceOfXYZ.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HSequenceOfXYZ::*)() const) &TColgp_HSequenceOfXYZ::DynamicType, "None");

// TYPEDEF: TCOLGP_ARRAY1OFDIR2D
bind_NCollection_Array1<gp_Dir2d>(mod, "TColgp_Array1OfDir2d", py::module_local(false));

// CLASS: TCOLGP_HARRAY1OFDIR2D
py::class_<TColgp_HArray1OfDir2d, opencascade::handle<TColgp_HArray1OfDir2d>, Standard_Transient> cls_TColgp_HArray1OfDir2d(mod, "TColgp_HArray1OfDir2d", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HArray1OfDir2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TColgp_HArray1OfDir2d.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfDir2d::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TColgp_HArray1OfDir2d.def(py::init<const TColgp_Array1OfDir2d &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HArray1OfDir2d.def_static("operator new_", (void * (*)(size_t)) &TColgp_HArray1OfDir2d::operator new, "None", py::arg("theSize"));
// cls_TColgp_HArray1OfDir2d.def_static("operator delete_", (void (*)(void *)) &TColgp_HArray1OfDir2d::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HArray1OfDir2d.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HArray1OfDir2d::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HArray1OfDir2d.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HArray1OfDir2d::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HArray1OfDir2d.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HArray1OfDir2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HArray1OfDir2d.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HArray1OfDir2d::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HArray1OfDir2d.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray1OfDir2d::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HArray1OfDir2d.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray1OfDir2d::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HArray1OfDir2d.def("Array1", (const TColgp_Array1OfDir2d & (TColgp_HArray1OfDir2d::*)() const) &TColgp_HArray1OfDir2d::Array1, "None");
cls_TColgp_HArray1OfDir2d.def("ChangeArray1", (TColgp_Array1OfDir2d & (TColgp_HArray1OfDir2d::*)()) &TColgp_HArray1OfDir2d::ChangeArray1, "None");
cls_TColgp_HArray1OfDir2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfDir2d::get_type_name, "None");
cls_TColgp_HArray1OfDir2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfDir2d::get_type_descriptor, "None");
cls_TColgp_HArray1OfDir2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfDir2d::*)() const) &TColgp_HArray1OfDir2d::DynamicType, "None");

// CLASS: TCOLGP_HARRAY1OFLIN2D
py::class_<TColgp_HArray1OfLin2d, opencascade::handle<TColgp_HArray1OfLin2d>, Standard_Transient> cls_TColgp_HArray1OfLin2d(mod, "TColgp_HArray1OfLin2d", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HArray1OfLin2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TColgp_HArray1OfLin2d.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfLin2d::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TColgp_HArray1OfLin2d.def(py::init<const TColgp_Array1OfLin2d &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HArray1OfLin2d.def_static("operator new_", (void * (*)(size_t)) &TColgp_HArray1OfLin2d::operator new, "None", py::arg("theSize"));
// cls_TColgp_HArray1OfLin2d.def_static("operator delete_", (void (*)(void *)) &TColgp_HArray1OfLin2d::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HArray1OfLin2d.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HArray1OfLin2d::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HArray1OfLin2d.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HArray1OfLin2d::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HArray1OfLin2d.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HArray1OfLin2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HArray1OfLin2d.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HArray1OfLin2d::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HArray1OfLin2d.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray1OfLin2d::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HArray1OfLin2d.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray1OfLin2d::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HArray1OfLin2d.def("Array1", (const TColgp_Array1OfLin2d & (TColgp_HArray1OfLin2d::*)() const) &TColgp_HArray1OfLin2d::Array1, "None");
cls_TColgp_HArray1OfLin2d.def("ChangeArray1", (TColgp_Array1OfLin2d & (TColgp_HArray1OfLin2d::*)()) &TColgp_HArray1OfLin2d::ChangeArray1, "None");
cls_TColgp_HArray1OfLin2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfLin2d::get_type_name, "None");
cls_TColgp_HArray1OfLin2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfLin2d::get_type_descriptor, "None");
cls_TColgp_HArray1OfLin2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfLin2d::*)() const) &TColgp_HArray1OfLin2d::DynamicType, "None");

// CLASS: TCOLGP_HARRAY1OFCIRC2D
py::class_<TColgp_HArray1OfCirc2d, opencascade::handle<TColgp_HArray1OfCirc2d>, Standard_Transient> cls_TColgp_HArray1OfCirc2d(mod, "TColgp_HArray1OfCirc2d", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HArray1OfCirc2d.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TColgp_HArray1OfCirc2d.def(py::init<const Standard_Integer, const Standard_Integer, const TColgp_Array1OfCirc2d::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TColgp_HArray1OfCirc2d.def(py::init<const TColgp_Array1OfCirc2d &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HArray1OfCirc2d.def_static("operator new_", (void * (*)(size_t)) &TColgp_HArray1OfCirc2d::operator new, "None", py::arg("theSize"));
// cls_TColgp_HArray1OfCirc2d.def_static("operator delete_", (void (*)(void *)) &TColgp_HArray1OfCirc2d::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HArray1OfCirc2d.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HArray1OfCirc2d::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HArray1OfCirc2d.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HArray1OfCirc2d::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HArray1OfCirc2d.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HArray1OfCirc2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HArray1OfCirc2d.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HArray1OfCirc2d::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HArray1OfCirc2d.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray1OfCirc2d::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HArray1OfCirc2d.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray1OfCirc2d::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HArray1OfCirc2d.def("Array1", (const TColgp_Array1OfCirc2d & (TColgp_HArray1OfCirc2d::*)() const) &TColgp_HArray1OfCirc2d::Array1, "None");
cls_TColgp_HArray1OfCirc2d.def("ChangeArray1", (TColgp_Array1OfCirc2d & (TColgp_HArray1OfCirc2d::*)()) &TColgp_HArray1OfCirc2d::ChangeArray1, "None");
cls_TColgp_HArray1OfCirc2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray1OfCirc2d::get_type_name, "None");
cls_TColgp_HArray1OfCirc2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray1OfCirc2d::get_type_descriptor, "None");
cls_TColgp_HArray1OfCirc2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray1OfCirc2d::*)() const) &TColgp_HArray1OfCirc2d::DynamicType, "None");

// TYPEDEF: TCOLGP_ARRAY2OFDIR
bind_NCollection_Array2<gp_Dir>(mod, "TColgp_Array2OfDir", py::module_local(false));

// CLASS: TCOLGP_HARRAY2OFDIR
py::class_<TColgp_HArray2OfDir, opencascade::handle<TColgp_HArray2OfDir>, Standard_Transient> cls_TColgp_HArray2OfDir(mod, "TColgp_HArray2OfDir", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HArray2OfDir.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_TColgp_HArray2OfDir.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfDir::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_TColgp_HArray2OfDir.def(py::init<const TColgp_Array2OfDir &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HArray2OfDir.def_static("operator new_", (void * (*)(size_t)) &TColgp_HArray2OfDir::operator new, "None", py::arg("theSize"));
// cls_TColgp_HArray2OfDir.def_static("operator delete_", (void (*)(void *)) &TColgp_HArray2OfDir::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HArray2OfDir.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HArray2OfDir::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HArray2OfDir.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HArray2OfDir::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HArray2OfDir.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HArray2OfDir::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HArray2OfDir.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HArray2OfDir::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HArray2OfDir.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray2OfDir::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HArray2OfDir.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray2OfDir::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HArray2OfDir.def("Array2", (const TColgp_Array2OfDir & (TColgp_HArray2OfDir::*)() const) &TColgp_HArray2OfDir::Array2, "None");
cls_TColgp_HArray2OfDir.def("ChangeArray2", (TColgp_Array2OfDir & (TColgp_HArray2OfDir::*)()) &TColgp_HArray2OfDir::ChangeArray2, "None");
cls_TColgp_HArray2OfDir.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfDir::get_type_name, "None");
cls_TColgp_HArray2OfDir.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfDir::get_type_descriptor, "None");
cls_TColgp_HArray2OfDir.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfDir::*)() const) &TColgp_HArray2OfDir::DynamicType, "None");

// CLASS: TCOLGP_HARRAY2OFVEC
py::class_<TColgp_HArray2OfVec, opencascade::handle<TColgp_HArray2OfVec>, Standard_Transient> cls_TColgp_HArray2OfVec(mod, "TColgp_HArray2OfVec", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HArray2OfVec.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_TColgp_HArray2OfVec.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfVec::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_TColgp_HArray2OfVec.def(py::init<const TColgp_Array2OfVec &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HArray2OfVec.def_static("operator new_", (void * (*)(size_t)) &TColgp_HArray2OfVec::operator new, "None", py::arg("theSize"));
// cls_TColgp_HArray2OfVec.def_static("operator delete_", (void (*)(void *)) &TColgp_HArray2OfVec::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HArray2OfVec.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HArray2OfVec::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HArray2OfVec.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HArray2OfVec::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HArray2OfVec.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HArray2OfVec::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HArray2OfVec.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HArray2OfVec::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HArray2OfVec.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray2OfVec::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HArray2OfVec.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray2OfVec::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HArray2OfVec.def("Array2", (const TColgp_Array2OfVec & (TColgp_HArray2OfVec::*)() const) &TColgp_HArray2OfVec::Array2, "None");
cls_TColgp_HArray2OfVec.def("ChangeArray2", (TColgp_Array2OfVec & (TColgp_HArray2OfVec::*)()) &TColgp_HArray2OfVec::ChangeArray2, "None");
cls_TColgp_HArray2OfVec.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfVec::get_type_name, "None");
cls_TColgp_HArray2OfVec.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfVec::get_type_descriptor, "None");
cls_TColgp_HArray2OfVec.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfVec::*)() const) &TColgp_HArray2OfVec::DynamicType, "None");

// TYPEDEF: TCOLGP_ARRAY2OFXY
bind_NCollection_Array2<gp_XY>(mod, "TColgp_Array2OfXY", py::module_local(false));

// CLASS: TCOLGP_HARRAY2OFXY
py::class_<TColgp_HArray2OfXY, opencascade::handle<TColgp_HArray2OfXY>, Standard_Transient> cls_TColgp_HArray2OfXY(mod, "TColgp_HArray2OfXY", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HArray2OfXY.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_TColgp_HArray2OfXY.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfXY::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_TColgp_HArray2OfXY.def(py::init<const TColgp_Array2OfXY &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HArray2OfXY.def_static("operator new_", (void * (*)(size_t)) &TColgp_HArray2OfXY::operator new, "None", py::arg("theSize"));
// cls_TColgp_HArray2OfXY.def_static("operator delete_", (void (*)(void *)) &TColgp_HArray2OfXY::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HArray2OfXY.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HArray2OfXY::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HArray2OfXY.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HArray2OfXY::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HArray2OfXY.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HArray2OfXY::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HArray2OfXY.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HArray2OfXY::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HArray2OfXY.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray2OfXY::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HArray2OfXY.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray2OfXY::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HArray2OfXY.def("Array2", (const TColgp_Array2OfXY & (TColgp_HArray2OfXY::*)() const) &TColgp_HArray2OfXY::Array2, "None");
cls_TColgp_HArray2OfXY.def("ChangeArray2", (TColgp_Array2OfXY & (TColgp_HArray2OfXY::*)()) &TColgp_HArray2OfXY::ChangeArray2, "None");
cls_TColgp_HArray2OfXY.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfXY::get_type_name, "None");
cls_TColgp_HArray2OfXY.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfXY::get_type_descriptor, "None");
cls_TColgp_HArray2OfXY.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfXY::*)() const) &TColgp_HArray2OfXY::DynamicType, "None");

// TYPEDEF: TCOLGP_ARRAY2OFDIR2D
bind_NCollection_Array2<gp_Dir2d>(mod, "TColgp_Array2OfDir2d", py::module_local(false));

// CLASS: TCOLGP_HARRAY2OFDIR2D
py::class_<TColgp_HArray2OfDir2d, opencascade::handle<TColgp_HArray2OfDir2d>, Standard_Transient> cls_TColgp_HArray2OfDir2d(mod, "TColgp_HArray2OfDir2d", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HArray2OfDir2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_TColgp_HArray2OfDir2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfDir2d::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_TColgp_HArray2OfDir2d.def(py::init<const TColgp_Array2OfDir2d &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HArray2OfDir2d.def_static("operator new_", (void * (*)(size_t)) &TColgp_HArray2OfDir2d::operator new, "None", py::arg("theSize"));
// cls_TColgp_HArray2OfDir2d.def_static("operator delete_", (void (*)(void *)) &TColgp_HArray2OfDir2d::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HArray2OfDir2d.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HArray2OfDir2d::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HArray2OfDir2d.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HArray2OfDir2d::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HArray2OfDir2d.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HArray2OfDir2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HArray2OfDir2d.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HArray2OfDir2d::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HArray2OfDir2d.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray2OfDir2d::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HArray2OfDir2d.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray2OfDir2d::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HArray2OfDir2d.def("Array2", (const TColgp_Array2OfDir2d & (TColgp_HArray2OfDir2d::*)() const) &TColgp_HArray2OfDir2d::Array2, "None");
cls_TColgp_HArray2OfDir2d.def("ChangeArray2", (TColgp_Array2OfDir2d & (TColgp_HArray2OfDir2d::*)()) &TColgp_HArray2OfDir2d::ChangeArray2, "None");
cls_TColgp_HArray2OfDir2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfDir2d::get_type_name, "None");
cls_TColgp_HArray2OfDir2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfDir2d::get_type_descriptor, "None");
cls_TColgp_HArray2OfDir2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfDir2d::*)() const) &TColgp_HArray2OfDir2d::DynamicType, "None");

// TYPEDEF: TCOLGP_ARRAY2OFVEC2D
bind_NCollection_Array2<gp_Vec2d>(mod, "TColgp_Array2OfVec2d", py::module_local(false));

// CLASS: TCOLGP_HARRAY2OFVEC2D
py::class_<TColgp_HArray2OfVec2d, opencascade::handle<TColgp_HArray2OfVec2d>, Standard_Transient> cls_TColgp_HArray2OfVec2d(mod, "TColgp_HArray2OfVec2d", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HArray2OfVec2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_TColgp_HArray2OfVec2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfVec2d::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_TColgp_HArray2OfVec2d.def(py::init<const TColgp_Array2OfVec2d &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HArray2OfVec2d.def_static("operator new_", (void * (*)(size_t)) &TColgp_HArray2OfVec2d::operator new, "None", py::arg("theSize"));
// cls_TColgp_HArray2OfVec2d.def_static("operator delete_", (void (*)(void *)) &TColgp_HArray2OfVec2d::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HArray2OfVec2d.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HArray2OfVec2d::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HArray2OfVec2d.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HArray2OfVec2d::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HArray2OfVec2d.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HArray2OfVec2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HArray2OfVec2d.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HArray2OfVec2d::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HArray2OfVec2d.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray2OfVec2d::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HArray2OfVec2d.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray2OfVec2d::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HArray2OfVec2d.def("Array2", (const TColgp_Array2OfVec2d & (TColgp_HArray2OfVec2d::*)() const) &TColgp_HArray2OfVec2d::Array2, "None");
cls_TColgp_HArray2OfVec2d.def("ChangeArray2", (TColgp_Array2OfVec2d & (TColgp_HArray2OfVec2d::*)()) &TColgp_HArray2OfVec2d::ChangeArray2, "None");
cls_TColgp_HArray2OfVec2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfVec2d::get_type_name, "None");
cls_TColgp_HArray2OfVec2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfVec2d::get_type_descriptor, "None");
cls_TColgp_HArray2OfVec2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfVec2d::*)() const) &TColgp_HArray2OfVec2d::DynamicType, "None");

// TYPEDEF: TCOLGP_ARRAY2OFLIN2D
bind_NCollection_Array2<gp_Lin2d>(mod, "TColgp_Array2OfLin2d", py::module_local(false));

// CLASS: TCOLGP_HARRAY2OFLIN2D
py::class_<TColgp_HArray2OfLin2d, opencascade::handle<TColgp_HArray2OfLin2d>, Standard_Transient> cls_TColgp_HArray2OfLin2d(mod, "TColgp_HArray2OfLin2d", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HArray2OfLin2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_TColgp_HArray2OfLin2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfLin2d::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_TColgp_HArray2OfLin2d.def(py::init<const TColgp_Array2OfLin2d &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HArray2OfLin2d.def_static("operator new_", (void * (*)(size_t)) &TColgp_HArray2OfLin2d::operator new, "None", py::arg("theSize"));
// cls_TColgp_HArray2OfLin2d.def_static("operator delete_", (void (*)(void *)) &TColgp_HArray2OfLin2d::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HArray2OfLin2d.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HArray2OfLin2d::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HArray2OfLin2d.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HArray2OfLin2d::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HArray2OfLin2d.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HArray2OfLin2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HArray2OfLin2d.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HArray2OfLin2d::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HArray2OfLin2d.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray2OfLin2d::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HArray2OfLin2d.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray2OfLin2d::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HArray2OfLin2d.def("Array2", (const TColgp_Array2OfLin2d & (TColgp_HArray2OfLin2d::*)() const) &TColgp_HArray2OfLin2d::Array2, "None");
cls_TColgp_HArray2OfLin2d.def("ChangeArray2", (TColgp_Array2OfLin2d & (TColgp_HArray2OfLin2d::*)()) &TColgp_HArray2OfLin2d::ChangeArray2, "None");
cls_TColgp_HArray2OfLin2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfLin2d::get_type_name, "None");
cls_TColgp_HArray2OfLin2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfLin2d::get_type_descriptor, "None");
cls_TColgp_HArray2OfLin2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfLin2d::*)() const) &TColgp_HArray2OfLin2d::DynamicType, "None");

// TYPEDEF: TCOLGP_ARRAY2OFCIRC2D
bind_NCollection_Array2<gp_Circ2d>(mod, "TColgp_Array2OfCirc2d", py::module_local(false));

// CLASS: TCOLGP_HARRAY2OFCIRC2D
py::class_<TColgp_HArray2OfCirc2d, opencascade::handle<TColgp_HArray2OfCirc2d>, Standard_Transient> cls_TColgp_HArray2OfCirc2d(mod, "TColgp_HArray2OfCirc2d", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HArray2OfCirc2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
cls_TColgp_HArray2OfCirc2d.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColgp_Array2OfCirc2d::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
cls_TColgp_HArray2OfCirc2d.def(py::init<const TColgp_Array2OfCirc2d &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HArray2OfCirc2d.def_static("operator new_", (void * (*)(size_t)) &TColgp_HArray2OfCirc2d::operator new, "None", py::arg("theSize"));
// cls_TColgp_HArray2OfCirc2d.def_static("operator delete_", (void (*)(void *)) &TColgp_HArray2OfCirc2d::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HArray2OfCirc2d.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HArray2OfCirc2d::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HArray2OfCirc2d.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HArray2OfCirc2d::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HArray2OfCirc2d.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HArray2OfCirc2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HArray2OfCirc2d.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HArray2OfCirc2d::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HArray2OfCirc2d.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray2OfCirc2d::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HArray2OfCirc2d.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HArray2OfCirc2d::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HArray2OfCirc2d.def("Array2", (const TColgp_Array2OfCirc2d & (TColgp_HArray2OfCirc2d::*)() const) &TColgp_HArray2OfCirc2d::Array2, "None");
cls_TColgp_HArray2OfCirc2d.def("ChangeArray2", (TColgp_Array2OfCirc2d & (TColgp_HArray2OfCirc2d::*)()) &TColgp_HArray2OfCirc2d::ChangeArray2, "None");
cls_TColgp_HArray2OfCirc2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HArray2OfCirc2d::get_type_name, "None");
cls_TColgp_HArray2OfCirc2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HArray2OfCirc2d::get_type_descriptor, "None");
cls_TColgp_HArray2OfCirc2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HArray2OfCirc2d::*)() const) &TColgp_HArray2OfCirc2d::DynamicType, "None");

// TYPEDEF: TCOLGP_SEQUENCEOFDIR
bind_NCollection_Sequence<gp_Dir>(mod, "TColgp_SequenceOfDir", py::module_local(false));

// CLASS: TCOLGP_HSEQUENCEOFDIR
py::class_<TColgp_HSequenceOfDir, opencascade::handle<TColgp_HSequenceOfDir>, Standard_Transient> cls_TColgp_HSequenceOfDir(mod, "TColgp_HSequenceOfDir", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HSequenceOfDir.def(py::init<>());
cls_TColgp_HSequenceOfDir.def(py::init<const TColgp_SequenceOfDir &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HSequenceOfDir.def_static("operator new_", (void * (*)(size_t)) &TColgp_HSequenceOfDir::operator new, "None", py::arg("theSize"));
// cls_TColgp_HSequenceOfDir.def_static("operator delete_", (void (*)(void *)) &TColgp_HSequenceOfDir::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HSequenceOfDir.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HSequenceOfDir::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HSequenceOfDir.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HSequenceOfDir::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HSequenceOfDir.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HSequenceOfDir::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HSequenceOfDir.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HSequenceOfDir::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HSequenceOfDir.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HSequenceOfDir::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HSequenceOfDir.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HSequenceOfDir::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HSequenceOfDir.def("Sequence", (const TColgp_SequenceOfDir & (TColgp_HSequenceOfDir::*)() const) &TColgp_HSequenceOfDir::Sequence, "None");
cls_TColgp_HSequenceOfDir.def("Append", (void (TColgp_HSequenceOfDir::*)(const TColgp_SequenceOfDir::value_type &)) &TColgp_HSequenceOfDir::Append, "None", py::arg("theItem"));
cls_TColgp_HSequenceOfDir.def("Append", (void (TColgp_HSequenceOfDir::*)(TColgp_SequenceOfDir &)) &TColgp_HSequenceOfDir::Append, "None", py::arg("theSequence"));
cls_TColgp_HSequenceOfDir.def("ChangeSequence", (TColgp_SequenceOfDir & (TColgp_HSequenceOfDir::*)()) &TColgp_HSequenceOfDir::ChangeSequence, "None");
cls_TColgp_HSequenceOfDir.def_static("get_type_name_", (const char * (*)()) &TColgp_HSequenceOfDir::get_type_name, "None");
cls_TColgp_HSequenceOfDir.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HSequenceOfDir::get_type_descriptor, "None");
cls_TColgp_HSequenceOfDir.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HSequenceOfDir::*)() const) &TColgp_HSequenceOfDir::DynamicType, "None");

// CLASS: TCOLGP_HSEQUENCEOFVEC
py::class_<TColgp_HSequenceOfVec, opencascade::handle<TColgp_HSequenceOfVec>, Standard_Transient> cls_TColgp_HSequenceOfVec(mod, "TColgp_HSequenceOfVec", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HSequenceOfVec.def(py::init<>());
cls_TColgp_HSequenceOfVec.def(py::init<const TColgp_SequenceOfVec &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HSequenceOfVec.def_static("operator new_", (void * (*)(size_t)) &TColgp_HSequenceOfVec::operator new, "None", py::arg("theSize"));
// cls_TColgp_HSequenceOfVec.def_static("operator delete_", (void (*)(void *)) &TColgp_HSequenceOfVec::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HSequenceOfVec.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HSequenceOfVec::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HSequenceOfVec.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HSequenceOfVec::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HSequenceOfVec.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HSequenceOfVec::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HSequenceOfVec.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HSequenceOfVec::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HSequenceOfVec.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HSequenceOfVec::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HSequenceOfVec.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HSequenceOfVec::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HSequenceOfVec.def("Sequence", (const TColgp_SequenceOfVec & (TColgp_HSequenceOfVec::*)() const) &TColgp_HSequenceOfVec::Sequence, "None");
cls_TColgp_HSequenceOfVec.def("Append", (void (TColgp_HSequenceOfVec::*)(const TColgp_SequenceOfVec::value_type &)) &TColgp_HSequenceOfVec::Append, "None", py::arg("theItem"));
cls_TColgp_HSequenceOfVec.def("Append", (void (TColgp_HSequenceOfVec::*)(TColgp_SequenceOfVec &)) &TColgp_HSequenceOfVec::Append, "None", py::arg("theSequence"));
cls_TColgp_HSequenceOfVec.def("ChangeSequence", (TColgp_SequenceOfVec & (TColgp_HSequenceOfVec::*)()) &TColgp_HSequenceOfVec::ChangeSequence, "None");
cls_TColgp_HSequenceOfVec.def_static("get_type_name_", (const char * (*)()) &TColgp_HSequenceOfVec::get_type_name, "None");
cls_TColgp_HSequenceOfVec.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HSequenceOfVec::get_type_descriptor, "None");
cls_TColgp_HSequenceOfVec.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HSequenceOfVec::*)() const) &TColgp_HSequenceOfVec::DynamicType, "None");

// TYPEDEF: TCOLGP_SEQUENCEOFDIR2D
bind_NCollection_Sequence<gp_Dir2d>(mod, "TColgp_SequenceOfDir2d", py::module_local(false));

// CLASS: TCOLGP_HSEQUENCEOFDIR2D
py::class_<TColgp_HSequenceOfDir2d, opencascade::handle<TColgp_HSequenceOfDir2d>, Standard_Transient> cls_TColgp_HSequenceOfDir2d(mod, "TColgp_HSequenceOfDir2d", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HSequenceOfDir2d.def(py::init<>());
cls_TColgp_HSequenceOfDir2d.def(py::init<const TColgp_SequenceOfDir2d &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HSequenceOfDir2d.def_static("operator new_", (void * (*)(size_t)) &TColgp_HSequenceOfDir2d::operator new, "None", py::arg("theSize"));
// cls_TColgp_HSequenceOfDir2d.def_static("operator delete_", (void (*)(void *)) &TColgp_HSequenceOfDir2d::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HSequenceOfDir2d.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HSequenceOfDir2d::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HSequenceOfDir2d.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HSequenceOfDir2d::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HSequenceOfDir2d.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HSequenceOfDir2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HSequenceOfDir2d.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HSequenceOfDir2d::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HSequenceOfDir2d.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HSequenceOfDir2d::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HSequenceOfDir2d.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HSequenceOfDir2d::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HSequenceOfDir2d.def("Sequence", (const TColgp_SequenceOfDir2d & (TColgp_HSequenceOfDir2d::*)() const) &TColgp_HSequenceOfDir2d::Sequence, "None");
cls_TColgp_HSequenceOfDir2d.def("Append", (void (TColgp_HSequenceOfDir2d::*)(const TColgp_SequenceOfDir2d::value_type &)) &TColgp_HSequenceOfDir2d::Append, "None", py::arg("theItem"));
cls_TColgp_HSequenceOfDir2d.def("Append", (void (TColgp_HSequenceOfDir2d::*)(TColgp_SequenceOfDir2d &)) &TColgp_HSequenceOfDir2d::Append, "None", py::arg("theSequence"));
cls_TColgp_HSequenceOfDir2d.def("ChangeSequence", (TColgp_SequenceOfDir2d & (TColgp_HSequenceOfDir2d::*)()) &TColgp_HSequenceOfDir2d::ChangeSequence, "None");
cls_TColgp_HSequenceOfDir2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HSequenceOfDir2d::get_type_name, "None");
cls_TColgp_HSequenceOfDir2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HSequenceOfDir2d::get_type_descriptor, "None");
cls_TColgp_HSequenceOfDir2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HSequenceOfDir2d::*)() const) &TColgp_HSequenceOfDir2d::DynamicType, "None");

// CLASS: TCOLGP_HSEQUENCEOFPNT2D
py::class_<TColgp_HSequenceOfPnt2d, opencascade::handle<TColgp_HSequenceOfPnt2d>, Standard_Transient> cls_TColgp_HSequenceOfPnt2d(mod, "TColgp_HSequenceOfPnt2d", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HSequenceOfPnt2d.def(py::init<>());
cls_TColgp_HSequenceOfPnt2d.def(py::init<const TColgp_SequenceOfPnt2d &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HSequenceOfPnt2d.def_static("operator new_", (void * (*)(size_t)) &TColgp_HSequenceOfPnt2d::operator new, "None", py::arg("theSize"));
// cls_TColgp_HSequenceOfPnt2d.def_static("operator delete_", (void (*)(void *)) &TColgp_HSequenceOfPnt2d::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HSequenceOfPnt2d.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HSequenceOfPnt2d::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HSequenceOfPnt2d.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HSequenceOfPnt2d::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HSequenceOfPnt2d.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HSequenceOfPnt2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HSequenceOfPnt2d.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HSequenceOfPnt2d::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HSequenceOfPnt2d.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HSequenceOfPnt2d::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HSequenceOfPnt2d.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HSequenceOfPnt2d::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HSequenceOfPnt2d.def("Sequence", (const TColgp_SequenceOfPnt2d & (TColgp_HSequenceOfPnt2d::*)() const) &TColgp_HSequenceOfPnt2d::Sequence, "None");
cls_TColgp_HSequenceOfPnt2d.def("Append", (void (TColgp_HSequenceOfPnt2d::*)(const TColgp_SequenceOfPnt2d::value_type &)) &TColgp_HSequenceOfPnt2d::Append, "None", py::arg("theItem"));
cls_TColgp_HSequenceOfPnt2d.def("Append", (void (TColgp_HSequenceOfPnt2d::*)(TColgp_SequenceOfPnt2d &)) &TColgp_HSequenceOfPnt2d::Append, "None", py::arg("theSequence"));
cls_TColgp_HSequenceOfPnt2d.def("ChangeSequence", (TColgp_SequenceOfPnt2d & (TColgp_HSequenceOfPnt2d::*)()) &TColgp_HSequenceOfPnt2d::ChangeSequence, "None");
cls_TColgp_HSequenceOfPnt2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HSequenceOfPnt2d::get_type_name, "None");
cls_TColgp_HSequenceOfPnt2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HSequenceOfPnt2d::get_type_descriptor, "None");
cls_TColgp_HSequenceOfPnt2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HSequenceOfPnt2d::*)() const) &TColgp_HSequenceOfPnt2d::DynamicType, "None");

// TYPEDEF: TCOLGP_SEQUENCEOFVEC2D
bind_NCollection_Sequence<gp_Vec2d>(mod, "TColgp_SequenceOfVec2d", py::module_local(false));

// CLASS: TCOLGP_HSEQUENCEOFVEC2D
py::class_<TColgp_HSequenceOfVec2d, opencascade::handle<TColgp_HSequenceOfVec2d>, Standard_Transient> cls_TColgp_HSequenceOfVec2d(mod, "TColgp_HSequenceOfVec2d", "None", py::multiple_inheritance());

// Constructors
cls_TColgp_HSequenceOfVec2d.def(py::init<>());
cls_TColgp_HSequenceOfVec2d.def(py::init<const TColgp_SequenceOfVec2d &>(), py::arg("theOther"));

// Methods
// cls_TColgp_HSequenceOfVec2d.def_static("operator new_", (void * (*)(size_t)) &TColgp_HSequenceOfVec2d::operator new, "None", py::arg("theSize"));
// cls_TColgp_HSequenceOfVec2d.def_static("operator delete_", (void (*)(void *)) &TColgp_HSequenceOfVec2d::operator delete, "None", py::arg("theAddress"));
// cls_TColgp_HSequenceOfVec2d.def_static("operator new[]_", (void * (*)(size_t)) &TColgp_HSequenceOfVec2d::operator new[], "None", py::arg("theSize"));
// cls_TColgp_HSequenceOfVec2d.def_static("operator delete[]_", (void (*)(void *)) &TColgp_HSequenceOfVec2d::operator delete[], "None", py::arg("theAddress"));
// cls_TColgp_HSequenceOfVec2d.def_static("operator new_", (void * (*)(size_t, void *)) &TColgp_HSequenceOfVec2d::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColgp_HSequenceOfVec2d.def_static("operator delete_", (void (*)(void *, void *)) &TColgp_HSequenceOfVec2d::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColgp_HSequenceOfVec2d.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HSequenceOfVec2d::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColgp_HSequenceOfVec2d.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColgp_HSequenceOfVec2d::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColgp_HSequenceOfVec2d.def("Sequence", (const TColgp_SequenceOfVec2d & (TColgp_HSequenceOfVec2d::*)() const) &TColgp_HSequenceOfVec2d::Sequence, "None");
cls_TColgp_HSequenceOfVec2d.def("Append", (void (TColgp_HSequenceOfVec2d::*)(const TColgp_SequenceOfVec2d::value_type &)) &TColgp_HSequenceOfVec2d::Append, "None", py::arg("theItem"));
cls_TColgp_HSequenceOfVec2d.def("Append", (void (TColgp_HSequenceOfVec2d::*)(TColgp_SequenceOfVec2d &)) &TColgp_HSequenceOfVec2d::Append, "None", py::arg("theSequence"));
cls_TColgp_HSequenceOfVec2d.def("ChangeSequence", (TColgp_SequenceOfVec2d & (TColgp_HSequenceOfVec2d::*)()) &TColgp_HSequenceOfVec2d::ChangeSequence, "None");
cls_TColgp_HSequenceOfVec2d.def_static("get_type_name_", (const char * (*)()) &TColgp_HSequenceOfVec2d::get_type_name, "None");
cls_TColgp_HSequenceOfVec2d.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColgp_HSequenceOfVec2d::get_type_descriptor, "None");
cls_TColgp_HSequenceOfVec2d.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColgp_HSequenceOfVec2d::*)() const) &TColgp_HSequenceOfVec2d::DynamicType, "None");


}
