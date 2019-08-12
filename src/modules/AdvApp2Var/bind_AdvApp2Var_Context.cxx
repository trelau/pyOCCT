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
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <TColStd_HArray1OfReal.hxx>
#include <TColStd_HArray2OfReal.hxx>
#include <AdvApp2Var_Context.hxx>

void bind_AdvApp2Var_Context(py::module &mod){

py::class_<AdvApp2Var_Context, std::unique_ptr<AdvApp2Var_Context, Deleter<AdvApp2Var_Context>>> cls_AdvApp2Var_Context(mod, "AdvApp2Var_Context", "contains all the parameters for approximation ( tolerancy, computing option, ...)");

// Constructors
cls_AdvApp2Var_Context.def(py::init<>());
cls_AdvApp2Var_Context.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray1OfReal> &, const opencascade::handle<TColStd_HArray2OfReal> &, const opencascade::handle<TColStd_HArray2OfReal> &, const opencascade::handle<TColStd_HArray2OfReal> &>(), py::arg("ifav"), py::arg("iu"), py::arg("iv"), py::arg("nlimu"), py::arg("nlimv"), py::arg("iprecis"), py::arg("nb1Dss"), py::arg("nb2Dss"), py::arg("nb3Dss"), py::arg("tol1D"), py::arg("tol2D"), py::arg("tol3D"), py::arg("tof1D"), py::arg("tof2D"), py::arg("tof3D"));

// Fields

// Methods
// cls_AdvApp2Var_Context.def_static("operator new_", (void * (*)(size_t)) &AdvApp2Var_Context::operator new, "None", py::arg("theSize"));
// cls_AdvApp2Var_Context.def_static("operator delete_", (void (*)(void *)) &AdvApp2Var_Context::operator delete, "None", py::arg("theAddress"));
// cls_AdvApp2Var_Context.def_static("operator new[]_", (void * (*)(size_t)) &AdvApp2Var_Context::operator new[], "None", py::arg("theSize"));
// cls_AdvApp2Var_Context.def_static("operator delete[]_", (void (*)(void *)) &AdvApp2Var_Context::operator delete[], "None", py::arg("theAddress"));
// cls_AdvApp2Var_Context.def_static("operator new_", (void * (*)(size_t, void *)) &AdvApp2Var_Context::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_AdvApp2Var_Context.def_static("operator delete_", (void (*)(void *, void *)) &AdvApp2Var_Context::operator delete, "None", py::arg(""), py::arg(""));
cls_AdvApp2Var_Context.def("TotalDimension", (Standard_Integer (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::TotalDimension, "None");
cls_AdvApp2Var_Context.def("TotalNumberSSP", (Standard_Integer (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::TotalNumberSSP, "None");
cls_AdvApp2Var_Context.def("FavorIso", (Standard_Integer (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::FavorIso, "None");
cls_AdvApp2Var_Context.def("UOrder", (Standard_Integer (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::UOrder, "None");
cls_AdvApp2Var_Context.def("VOrder", (Standard_Integer (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::VOrder, "None");
cls_AdvApp2Var_Context.def("ULimit", (Standard_Integer (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::ULimit, "None");
cls_AdvApp2Var_Context.def("VLimit", (Standard_Integer (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::VLimit, "None");
cls_AdvApp2Var_Context.def("UJacDeg", (Standard_Integer (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::UJacDeg, "None");
cls_AdvApp2Var_Context.def("VJacDeg", (Standard_Integer (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::VJacDeg, "None");
cls_AdvApp2Var_Context.def("UJacMax", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::UJacMax, "None");
cls_AdvApp2Var_Context.def("VJacMax", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::VJacMax, "None");
cls_AdvApp2Var_Context.def("URoots", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::URoots, "None");
cls_AdvApp2Var_Context.def("VRoots", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::VRoots, "None");
cls_AdvApp2Var_Context.def("UGauss", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::UGauss, "None");
cls_AdvApp2Var_Context.def("VGauss", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::VGauss, "None");
cls_AdvApp2Var_Context.def("IToler", (opencascade::handle<TColStd_HArray1OfReal> (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::IToler, "None");
cls_AdvApp2Var_Context.def("FToler", (opencascade::handle<TColStd_HArray2OfReal> (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::FToler, "None");
cls_AdvApp2Var_Context.def("CToler", (opencascade::handle<TColStd_HArray2OfReal> (AdvApp2Var_Context::*)() const) &AdvApp2Var_Context::CToler, "None");

// Enums

}