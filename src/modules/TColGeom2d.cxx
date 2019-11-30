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
#include <Standard_Handle.hxx>
#include <Geom2d_Curve.hxx>
#include <TColGeom2d_Array1OfCurve.hxx>
#include <Standard_Transient.hxx>
#include <Standard.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Std.hxx>
#include <TColGeom2d_HArray1OfCurve.hxx>
#include <Standard_Type.hxx>
#include <NCollection_Sequence.hxx>
#include <TColGeom2d_SequenceOfCurve.hxx>
#include <Geom2d_BSplineCurve.hxx>
#include <TColGeom2d_Array1OfBSplineCurve.hxx>
#include <TColGeom2d_HArray1OfBSplineCurve.hxx>
#include <Geom2d_BezierCurve.hxx>
#include <TColGeom2d_Array1OfBezierCurve.hxx>
#include <Geom2d_Geometry.hxx>
#include <TColGeom2d_SequenceOfGeometry.hxx>
#include <Geom2d_BoundedCurve.hxx>
#include <TColGeom2d_SequenceOfBoundedCurve.hxx>
#include <TColGeom2d_HSequenceOfBoundedCurve.hxx>
#include <TColGeom2d_HSequenceOfCurve.hxx>
#include <TColGeom2d_HArray1OfBezierCurve.hxx>
#include <bind_NCollection_Array1.hxx>
#include <bind_NCollection_Sequence.hxx>

PYBIND11_MODULE(TColGeom2d, mod) {

py::module::import("OCCT.NCollection");
py::module::import("OCCT.Standard");
py::module::import("OCCT.Geom2d");

// TYPEDEF: TCOLGEOM2D_ARRAY1OFCURVE
bind_NCollection_Array1<opencascade::handle<Geom2d_Curve> >(mod, "TColGeom2d_Array1OfCurve", py::module_local(false));

// CLASS: TCOLGEOM2D_HARRAY1OFCURVE
py::class_<TColGeom2d_HArray1OfCurve, opencascade::handle<TColGeom2d_HArray1OfCurve>, Standard_Transient> cls_TColGeom2d_HArray1OfCurve(mod, "TColGeom2d_HArray1OfCurve", "None", py::multiple_inheritance());

// Constructors
cls_TColGeom2d_HArray1OfCurve.def(py::init<>());
cls_TColGeom2d_HArray1OfCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TColGeom2d_HArray1OfCurve.def(py::init<const Standard_Integer, const Standard_Integer, const TColGeom2d_Array1OfCurve::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TColGeom2d_HArray1OfCurve.def(py::init<const TColGeom2d_Array1OfCurve &>(), py::arg("theOther"));

// Methods
// cls_TColGeom2d_HArray1OfCurve.def_static("operator new_", (void * (*)(size_t)) &TColGeom2d_HArray1OfCurve::operator new, "None", py::arg("theSize"));
// cls_TColGeom2d_HArray1OfCurve.def_static("operator delete_", (void (*)(void *)) &TColGeom2d_HArray1OfCurve::operator delete, "None", py::arg("theAddress"));
// cls_TColGeom2d_HArray1OfCurve.def_static("operator new[]_", (void * (*)(size_t)) &TColGeom2d_HArray1OfCurve::operator new[], "None", py::arg("theSize"));
// cls_TColGeom2d_HArray1OfCurve.def_static("operator delete[]_", (void (*)(void *)) &TColGeom2d_HArray1OfCurve::operator delete[], "None", py::arg("theAddress"));
// cls_TColGeom2d_HArray1OfCurve.def_static("operator new_", (void * (*)(size_t, void *)) &TColGeom2d_HArray1OfCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColGeom2d_HArray1OfCurve.def_static("operator delete_", (void (*)(void *, void *)) &TColGeom2d_HArray1OfCurve::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColGeom2d_HArray1OfCurve.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom2d_HArray1OfCurve::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColGeom2d_HArray1OfCurve.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom2d_HArray1OfCurve::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColGeom2d_HArray1OfCurve.def("Array1", (const TColGeom2d_Array1OfCurve & (TColGeom2d_HArray1OfCurve::*)() const) &TColGeom2d_HArray1OfCurve::Array1, "None");
cls_TColGeom2d_HArray1OfCurve.def("ChangeArray1", (TColGeom2d_Array1OfCurve & (TColGeom2d_HArray1OfCurve::*)()) &TColGeom2d_HArray1OfCurve::ChangeArray1, "None");
cls_TColGeom2d_HArray1OfCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom2d_HArray1OfCurve::get_type_name, "None");
cls_TColGeom2d_HArray1OfCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom2d_HArray1OfCurve::get_type_descriptor, "None");
cls_TColGeom2d_HArray1OfCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom2d_HArray1OfCurve::*)() const) &TColGeom2d_HArray1OfCurve::DynamicType, "None");

// TYPEDEF: TCOLGEOM2D_SEQUENCEOFCURVE
bind_NCollection_Sequence<opencascade::handle<Geom2d_Curve> >(mod, "TColGeom2d_SequenceOfCurve", py::module_local(false));

// TYPEDEF: TCOLGEOM2D_ARRAY1OFBSPLINECURVE
bind_NCollection_Array1<opencascade::handle<Geom2d_BSplineCurve> >(mod, "TColGeom2d_Array1OfBSplineCurve", py::module_local(false));

// CLASS: TCOLGEOM2D_HARRAY1OFBSPLINECURVE
py::class_<TColGeom2d_HArray1OfBSplineCurve, opencascade::handle<TColGeom2d_HArray1OfBSplineCurve>, Standard_Transient> cls_TColGeom2d_HArray1OfBSplineCurve(mod, "TColGeom2d_HArray1OfBSplineCurve", "None", py::multiple_inheritance());

// Constructors
cls_TColGeom2d_HArray1OfBSplineCurve.def(py::init<>());
cls_TColGeom2d_HArray1OfBSplineCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TColGeom2d_HArray1OfBSplineCurve.def(py::init<const Standard_Integer, const Standard_Integer, const TColGeom2d_Array1OfBSplineCurve::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TColGeom2d_HArray1OfBSplineCurve.def(py::init<const TColGeom2d_Array1OfBSplineCurve &>(), py::arg("theOther"));

// Methods
// cls_TColGeom2d_HArray1OfBSplineCurve.def_static("operator new_", (void * (*)(size_t)) &TColGeom2d_HArray1OfBSplineCurve::operator new, "None", py::arg("theSize"));
// cls_TColGeom2d_HArray1OfBSplineCurve.def_static("operator delete_", (void (*)(void *)) &TColGeom2d_HArray1OfBSplineCurve::operator delete, "None", py::arg("theAddress"));
// cls_TColGeom2d_HArray1OfBSplineCurve.def_static("operator new[]_", (void * (*)(size_t)) &TColGeom2d_HArray1OfBSplineCurve::operator new[], "None", py::arg("theSize"));
// cls_TColGeom2d_HArray1OfBSplineCurve.def_static("operator delete[]_", (void (*)(void *)) &TColGeom2d_HArray1OfBSplineCurve::operator delete[], "None", py::arg("theAddress"));
// cls_TColGeom2d_HArray1OfBSplineCurve.def_static("operator new_", (void * (*)(size_t, void *)) &TColGeom2d_HArray1OfBSplineCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColGeom2d_HArray1OfBSplineCurve.def_static("operator delete_", (void (*)(void *, void *)) &TColGeom2d_HArray1OfBSplineCurve::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColGeom2d_HArray1OfBSplineCurve.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom2d_HArray1OfBSplineCurve::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColGeom2d_HArray1OfBSplineCurve.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom2d_HArray1OfBSplineCurve::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColGeom2d_HArray1OfBSplineCurve.def("Array1", (const TColGeom2d_Array1OfBSplineCurve & (TColGeom2d_HArray1OfBSplineCurve::*)() const) &TColGeom2d_HArray1OfBSplineCurve::Array1, "None");
cls_TColGeom2d_HArray1OfBSplineCurve.def("ChangeArray1", (TColGeom2d_Array1OfBSplineCurve & (TColGeom2d_HArray1OfBSplineCurve::*)()) &TColGeom2d_HArray1OfBSplineCurve::ChangeArray1, "None");
cls_TColGeom2d_HArray1OfBSplineCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom2d_HArray1OfBSplineCurve::get_type_name, "None");
cls_TColGeom2d_HArray1OfBSplineCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom2d_HArray1OfBSplineCurve::get_type_descriptor, "None");
cls_TColGeom2d_HArray1OfBSplineCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom2d_HArray1OfBSplineCurve::*)() const) &TColGeom2d_HArray1OfBSplineCurve::DynamicType, "None");

// TYPEDEF: TCOLGEOM2D_ARRAY1OFBEZIERCURVE
bind_NCollection_Array1<opencascade::handle<Geom2d_BezierCurve> >(mod, "TColGeom2d_Array1OfBezierCurve", py::module_local(false));

// TYPEDEF: TCOLGEOM2D_SEQUENCEOFGEOMETRY
bind_NCollection_Sequence<opencascade::handle<Geom2d_Geometry> >(mod, "TColGeom2d_SequenceOfGeometry", py::module_local(false));

// TYPEDEF: TCOLGEOM2D_SEQUENCEOFBOUNDEDCURVE
bind_NCollection_Sequence<opencascade::handle<Geom2d_BoundedCurve> >(mod, "TColGeom2d_SequenceOfBoundedCurve", py::module_local(false));

// CLASS: TCOLGEOM2D_HSEQUENCEOFBOUNDEDCURVE
py::class_<TColGeom2d_HSequenceOfBoundedCurve, opencascade::handle<TColGeom2d_HSequenceOfBoundedCurve>, Standard_Transient> cls_TColGeom2d_HSequenceOfBoundedCurve(mod, "TColGeom2d_HSequenceOfBoundedCurve", "None", py::multiple_inheritance());

// Constructors
cls_TColGeom2d_HSequenceOfBoundedCurve.def(py::init<>());
cls_TColGeom2d_HSequenceOfBoundedCurve.def(py::init<const TColGeom2d_SequenceOfBoundedCurve &>(), py::arg("theOther"));

// Methods
// cls_TColGeom2d_HSequenceOfBoundedCurve.def_static("operator new_", (void * (*)(size_t)) &TColGeom2d_HSequenceOfBoundedCurve::operator new, "None", py::arg("theSize"));
// cls_TColGeom2d_HSequenceOfBoundedCurve.def_static("operator delete_", (void (*)(void *)) &TColGeom2d_HSequenceOfBoundedCurve::operator delete, "None", py::arg("theAddress"));
// cls_TColGeom2d_HSequenceOfBoundedCurve.def_static("operator new[]_", (void * (*)(size_t)) &TColGeom2d_HSequenceOfBoundedCurve::operator new[], "None", py::arg("theSize"));
// cls_TColGeom2d_HSequenceOfBoundedCurve.def_static("operator delete[]_", (void (*)(void *)) &TColGeom2d_HSequenceOfBoundedCurve::operator delete[], "None", py::arg("theAddress"));
// cls_TColGeom2d_HSequenceOfBoundedCurve.def_static("operator new_", (void * (*)(size_t, void *)) &TColGeom2d_HSequenceOfBoundedCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColGeom2d_HSequenceOfBoundedCurve.def_static("operator delete_", (void (*)(void *, void *)) &TColGeom2d_HSequenceOfBoundedCurve::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColGeom2d_HSequenceOfBoundedCurve.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom2d_HSequenceOfBoundedCurve::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColGeom2d_HSequenceOfBoundedCurve.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom2d_HSequenceOfBoundedCurve::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColGeom2d_HSequenceOfBoundedCurve.def("Sequence", (const TColGeom2d_SequenceOfBoundedCurve & (TColGeom2d_HSequenceOfBoundedCurve::*)() const) &TColGeom2d_HSequenceOfBoundedCurve::Sequence, "None");
cls_TColGeom2d_HSequenceOfBoundedCurve.def("Append", (void (TColGeom2d_HSequenceOfBoundedCurve::*)(const TColGeom2d_SequenceOfBoundedCurve::value_type &)) &TColGeom2d_HSequenceOfBoundedCurve::Append, "None", py::arg("theItem"));
cls_TColGeom2d_HSequenceOfBoundedCurve.def("Append", (void (TColGeom2d_HSequenceOfBoundedCurve::*)(TColGeom2d_SequenceOfBoundedCurve &)) &TColGeom2d_HSequenceOfBoundedCurve::Append, "None", py::arg("theSequence"));
cls_TColGeom2d_HSequenceOfBoundedCurve.def("ChangeSequence", (TColGeom2d_SequenceOfBoundedCurve & (TColGeom2d_HSequenceOfBoundedCurve::*)()) &TColGeom2d_HSequenceOfBoundedCurve::ChangeSequence, "None");
cls_TColGeom2d_HSequenceOfBoundedCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom2d_HSequenceOfBoundedCurve::get_type_name, "None");
cls_TColGeom2d_HSequenceOfBoundedCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom2d_HSequenceOfBoundedCurve::get_type_descriptor, "None");
cls_TColGeom2d_HSequenceOfBoundedCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom2d_HSequenceOfBoundedCurve::*)() const) &TColGeom2d_HSequenceOfBoundedCurve::DynamicType, "None");

// CLASS: TCOLGEOM2D_HSEQUENCEOFCURVE
py::class_<TColGeom2d_HSequenceOfCurve, opencascade::handle<TColGeom2d_HSequenceOfCurve>, Standard_Transient> cls_TColGeom2d_HSequenceOfCurve(mod, "TColGeom2d_HSequenceOfCurve", "None", py::multiple_inheritance());

// Constructors
cls_TColGeom2d_HSequenceOfCurve.def(py::init<>());
cls_TColGeom2d_HSequenceOfCurve.def(py::init<const TColGeom2d_SequenceOfCurve &>(), py::arg("theOther"));

// Methods
// cls_TColGeom2d_HSequenceOfCurve.def_static("operator new_", (void * (*)(size_t)) &TColGeom2d_HSequenceOfCurve::operator new, "None", py::arg("theSize"));
// cls_TColGeom2d_HSequenceOfCurve.def_static("operator delete_", (void (*)(void *)) &TColGeom2d_HSequenceOfCurve::operator delete, "None", py::arg("theAddress"));
// cls_TColGeom2d_HSequenceOfCurve.def_static("operator new[]_", (void * (*)(size_t)) &TColGeom2d_HSequenceOfCurve::operator new[], "None", py::arg("theSize"));
// cls_TColGeom2d_HSequenceOfCurve.def_static("operator delete[]_", (void (*)(void *)) &TColGeom2d_HSequenceOfCurve::operator delete[], "None", py::arg("theAddress"));
// cls_TColGeom2d_HSequenceOfCurve.def_static("operator new_", (void * (*)(size_t, void *)) &TColGeom2d_HSequenceOfCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColGeom2d_HSequenceOfCurve.def_static("operator delete_", (void (*)(void *, void *)) &TColGeom2d_HSequenceOfCurve::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColGeom2d_HSequenceOfCurve.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom2d_HSequenceOfCurve::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColGeom2d_HSequenceOfCurve.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom2d_HSequenceOfCurve::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColGeom2d_HSequenceOfCurve.def("Sequence", (const TColGeom2d_SequenceOfCurve & (TColGeom2d_HSequenceOfCurve::*)() const) &TColGeom2d_HSequenceOfCurve::Sequence, "None");
cls_TColGeom2d_HSequenceOfCurve.def("Append", (void (TColGeom2d_HSequenceOfCurve::*)(const TColGeom2d_SequenceOfCurve::value_type &)) &TColGeom2d_HSequenceOfCurve::Append, "None", py::arg("theItem"));
cls_TColGeom2d_HSequenceOfCurve.def("Append", (void (TColGeom2d_HSequenceOfCurve::*)(TColGeom2d_SequenceOfCurve &)) &TColGeom2d_HSequenceOfCurve::Append, "None", py::arg("theSequence"));
cls_TColGeom2d_HSequenceOfCurve.def("ChangeSequence", (TColGeom2d_SequenceOfCurve & (TColGeom2d_HSequenceOfCurve::*)()) &TColGeom2d_HSequenceOfCurve::ChangeSequence, "None");
cls_TColGeom2d_HSequenceOfCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom2d_HSequenceOfCurve::get_type_name, "None");
cls_TColGeom2d_HSequenceOfCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom2d_HSequenceOfCurve::get_type_descriptor, "None");
cls_TColGeom2d_HSequenceOfCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom2d_HSequenceOfCurve::*)() const) &TColGeom2d_HSequenceOfCurve::DynamicType, "None");

// CLASS: TCOLGEOM2D_HARRAY1OFBEZIERCURVE
py::class_<TColGeom2d_HArray1OfBezierCurve, opencascade::handle<TColGeom2d_HArray1OfBezierCurve>, Standard_Transient> cls_TColGeom2d_HArray1OfBezierCurve(mod, "TColGeom2d_HArray1OfBezierCurve", "None", py::multiple_inheritance());

// Constructors
cls_TColGeom2d_HArray1OfBezierCurve.def(py::init<>());
cls_TColGeom2d_HArray1OfBezierCurve.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
cls_TColGeom2d_HArray1OfBezierCurve.def(py::init<const Standard_Integer, const Standard_Integer, const TColGeom2d_Array1OfBezierCurve::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
cls_TColGeom2d_HArray1OfBezierCurve.def(py::init<const TColGeom2d_Array1OfBezierCurve &>(), py::arg("theOther"));

// Methods
// cls_TColGeom2d_HArray1OfBezierCurve.def_static("operator new_", (void * (*)(size_t)) &TColGeom2d_HArray1OfBezierCurve::operator new, "None", py::arg("theSize"));
// cls_TColGeom2d_HArray1OfBezierCurve.def_static("operator delete_", (void (*)(void *)) &TColGeom2d_HArray1OfBezierCurve::operator delete, "None", py::arg("theAddress"));
// cls_TColGeom2d_HArray1OfBezierCurve.def_static("operator new[]_", (void * (*)(size_t)) &TColGeom2d_HArray1OfBezierCurve::operator new[], "None", py::arg("theSize"));
// cls_TColGeom2d_HArray1OfBezierCurve.def_static("operator delete[]_", (void (*)(void *)) &TColGeom2d_HArray1OfBezierCurve::operator delete[], "None", py::arg("theAddress"));
// cls_TColGeom2d_HArray1OfBezierCurve.def_static("operator new_", (void * (*)(size_t, void *)) &TColGeom2d_HArray1OfBezierCurve::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_TColGeom2d_HArray1OfBezierCurve.def_static("operator delete_", (void (*)(void *, void *)) &TColGeom2d_HArray1OfBezierCurve::operator delete, "None", py::arg(""), py::arg(""));
// cls_TColGeom2d_HArray1OfBezierCurve.def_static("operator new_", (void * (*)(size_t, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom2d_HArray1OfBezierCurve::operator new, "None", py::arg("theSize"), py::arg("theAllocator"));
// cls_TColGeom2d_HArray1OfBezierCurve.def_static("operator delete_", (void (*)(void *, const opencascade::handle<NCollection_BaseAllocator> &)) &TColGeom2d_HArray1OfBezierCurve::operator delete, "None", py::arg("theAddress"), py::arg("theAllocator"));
cls_TColGeom2d_HArray1OfBezierCurve.def("Array1", (const TColGeom2d_Array1OfBezierCurve & (TColGeom2d_HArray1OfBezierCurve::*)() const) &TColGeom2d_HArray1OfBezierCurve::Array1, "None");
cls_TColGeom2d_HArray1OfBezierCurve.def("ChangeArray1", (TColGeom2d_Array1OfBezierCurve & (TColGeom2d_HArray1OfBezierCurve::*)()) &TColGeom2d_HArray1OfBezierCurve::ChangeArray1, "None");
cls_TColGeom2d_HArray1OfBezierCurve.def_static("get_type_name_", (const char * (*)()) &TColGeom2d_HArray1OfBezierCurve::get_type_name, "None");
cls_TColGeom2d_HArray1OfBezierCurve.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColGeom2d_HArray1OfBezierCurve::get_type_descriptor, "None");
cls_TColGeom2d_HArray1OfBezierCurve.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColGeom2d_HArray1OfBezierCurve::*)() const) &TColGeom2d_HArray1OfBezierCurve::DynamicType, "None");


}
