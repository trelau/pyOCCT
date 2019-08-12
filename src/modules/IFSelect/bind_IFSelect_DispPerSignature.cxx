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
#include <IFSelect_Dispatch.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_SignCounter.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <Interface_Graph.hxx>
#include <IFGraph_SubPartsIterator.hxx>
#include <IFSelect_DispPerSignature.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_DispPerSignature(py::module &mod){

py::class_<IFSelect_DispPerSignature, opencascade::handle<IFSelect_DispPerSignature>, IFSelect_Dispatch> cls_IFSelect_DispPerSignature(mod, "IFSelect_DispPerSignature", "A DispPerSignature sorts input Entities according to a Signature : it works with a SignCounter to do this.");

// Constructors
cls_IFSelect_DispPerSignature.def(py::init<>());

// Fields

// Methods
cls_IFSelect_DispPerSignature.def("SignCounter", (opencascade::handle<IFSelect_SignCounter> (IFSelect_DispPerSignature::*)() const) &IFSelect_DispPerSignature::SignCounter, "Returns the SignCounter used for splitting");
cls_IFSelect_DispPerSignature.def("SetSignCounter", (void (IFSelect_DispPerSignature::*)(const opencascade::handle<IFSelect_SignCounter> &)) &IFSelect_DispPerSignature::SetSignCounter, "Sets a SignCounter for sort Remark : it is set to record lists of entities, not only counts", py::arg("sign"));
cls_IFSelect_DispPerSignature.def("SignName", (Standard_CString (IFSelect_DispPerSignature::*)() const) &IFSelect_DispPerSignature::SignName, "Returns the name of the SignCounter, which caracterises the sorting criterium for this Dispatch");
cls_IFSelect_DispPerSignature.def("Label", (TCollection_AsciiString (IFSelect_DispPerSignature::*)() const) &IFSelect_DispPerSignature::Label, "Returns as Label, 'One File per Signature <name>'");
cls_IFSelect_DispPerSignature.def("LimitedMax", [](IFSelect_DispPerSignature &self, const Standard_Integer nbent, Standard_Integer & max){ Standard_Boolean rv = self.LimitedMax(nbent, max); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, max); }, "Returns True, maximum count is given as <nbent>", py::arg("nbent"), py::arg("max"));
cls_IFSelect_DispPerSignature.def("Packets", (void (IFSelect_DispPerSignature::*)(const Interface_Graph &, IFGraph_SubPartsIterator &) const) &IFSelect_DispPerSignature::Packets, "Computes the list of produced Packets. It defines Packets from the SignCounter, which sirts the input Entities per Signature (specific of the SignCounter).", py::arg("G"), py::arg("packs"));
cls_IFSelect_DispPerSignature.def_static("get_type_name_", (const char * (*)()) &IFSelect_DispPerSignature::get_type_name, "None");
cls_IFSelect_DispPerSignature.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_DispPerSignature::get_type_descriptor, "None");
cls_IFSelect_DispPerSignature.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_DispPerSignature::*)() const) &IFSelect_DispPerSignature::DynamicType, "None");

// Enums

}