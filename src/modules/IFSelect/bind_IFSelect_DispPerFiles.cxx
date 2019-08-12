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
#include <IFSelect_IntParam.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <Interface_Graph.hxx>
#include <IFGraph_SubPartsIterator.hxx>
#include <IFSelect_DispPerFiles.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_DispPerFiles(py::module &mod){

py::class_<IFSelect_DispPerFiles, opencascade::handle<IFSelect_DispPerFiles>, IFSelect_Dispatch> cls_IFSelect_DispPerFiles(mod, "IFSelect_DispPerFiles", "A DispPerFiles produces a determined count of Packets from the input Entities. It divides, as equally as possible, the input list into a count of files. This count is the parameter of the DispPerFiles. If the input list has less than this count, of course there will be one packet per input entity. This count is a Parameter of the DispPerFiles, given as an IntParam, thus allowing external control of its Value");

// Constructors
cls_IFSelect_DispPerFiles.def(py::init<>());

// Fields

// Methods
cls_IFSelect_DispPerFiles.def("Count", (opencascade::handle<IFSelect_IntParam> (IFSelect_DispPerFiles::*)() const) &IFSelect_DispPerFiles::Count, "Returns the Count Parameter used for splitting");
cls_IFSelect_DispPerFiles.def("SetCount", (void (IFSelect_DispPerFiles::*)(const opencascade::handle<IFSelect_IntParam> &)) &IFSelect_DispPerFiles::SetCount, "Sets a new Parameter for Count", py::arg("count"));
cls_IFSelect_DispPerFiles.def("CountValue", (Standard_Integer (IFSelect_DispPerFiles::*)() const) &IFSelect_DispPerFiles::CountValue, "Returns the effective value of the count parameter (if Count Parameter not Set or value not positive, returns 1)");
cls_IFSelect_DispPerFiles.def("Label", (TCollection_AsciiString (IFSelect_DispPerFiles::*)() const) &IFSelect_DispPerFiles::Label, "Returns as Label, 'Maximum <count> Files'");
cls_IFSelect_DispPerFiles.def("LimitedMax", [](IFSelect_DispPerFiles &self, const Standard_Integer nbent, Standard_Integer & max){ Standard_Boolean rv = self.LimitedMax(nbent, max); return std::tuple<Standard_Boolean, Standard_Integer &>(rv, max); }, "Returns True, maximum count is given as CountValue", py::arg("nbent"), py::arg("max"));
cls_IFSelect_DispPerFiles.def("Packets", (void (IFSelect_DispPerFiles::*)(const Interface_Graph &, IFGraph_SubPartsIterator &) const) &IFSelect_DispPerFiles::Packets, "Computes the list of produced Packets. It defines Packets in order to have <Count> Packets, except if the input count of Entities is lower. Entities are given by RootResult from the Final Selection.", py::arg("G"), py::arg("packs"));
cls_IFSelect_DispPerFiles.def_static("get_type_name_", (const char * (*)()) &IFSelect_DispPerFiles::get_type_name, "None");
cls_IFSelect_DispPerFiles.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_DispPerFiles::get_type_descriptor, "None");
cls_IFSelect_DispPerFiles.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_DispPerFiles::*)() const) &IFSelect_DispPerFiles::DynamicType, "None");

// Enums

}