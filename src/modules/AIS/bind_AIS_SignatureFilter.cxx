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
#include <AIS_TypeFilter.hxx>
#include <AIS_KindOfInteractive.hxx>
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <SelectMgr_EntityOwner.hxx>
#include <AIS_SignatureFilter.hxx>
#include <Standard_Type.hxx>

void bind_AIS_SignatureFilter(py::module &mod){

py::class_<AIS_SignatureFilter, opencascade::handle<AIS_SignatureFilter>, AIS_TypeFilter> cls_AIS_SignatureFilter(mod, "AIS_SignatureFilter", "Selects Interactive Objects through their signatures and types. The signature provides an additional characterization of an object's type, and takes the form of an index. The filter questions each Interactive Object in local context to determine whether it has an non-null owner, and if so, whether it has the desired signature. If the object returns true in each case, it is kept. If not, it is rejected. By default, the interactive object has a None type and a signature of 0. If you want to give a particular type and signature to your Interactive Object, you must redefine two virtual methods: Type and Signature. This filter is only used in an open local contexts. In the Collector viewer, you can only locate Interactive Objects which answer positively to the positioned filters when a local context is open. Warning Some signatures have already been used by standard objects delivered in AIS. These include: - signature 0 - Shape - signature 1 - Point - signature 2 - Axis - signature 3 - Trihedron - signature 4 - PlaneTrihedron - signature 5 - Line - signature 6 - Circle - signature 7 - Plane");

// Constructors
cls_AIS_SignatureFilter.def(py::init<const AIS_KindOfInteractive, const Standard_Integer>(), py::arg("aGivenKind"), py::arg("aGivenSignature"));

// Fields

// Methods
cls_AIS_SignatureFilter.def("IsOk", (Standard_Boolean (AIS_SignatureFilter::*)(const opencascade::handle<SelectMgr_EntityOwner> &) const) &AIS_SignatureFilter::IsOk, "Returns False if the transient is not an AIS_InteractiveObject. Returns False if the signature of InteractiveObject is not the same as the stored one in the filter...", py::arg("anobj"));
cls_AIS_SignatureFilter.def_static("get_type_name_", (const char * (*)()) &AIS_SignatureFilter::get_type_name, "None");
cls_AIS_SignatureFilter.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &AIS_SignatureFilter::get_type_descriptor, "None");
cls_AIS_SignatureFilter.def("DynamicType", (const opencascade::handle<Standard_Type> & (AIS_SignatureFilter::*)() const) &AIS_SignatureFilter::DynamicType, "None");

// Enums

}