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
#include <Standard_Transient.hxx>
#include <Standard_TypeDef.hxx>
#include <Interface_Graph.hxx>
#include <Standard_Handle.hxx>
#include <Interface_Protocol.hxx>
#include <Interface_CheckIterator.hxx>
#include <Interface_InterfaceModel.hxx>
#include <TCollection_AsciiString.hxx>
#include <IFSelect_Transformer.hxx>
#include <Standard_Type.hxx>

void bind_IFSelect_Transformer(py::module &mod){

py::class_<IFSelect_Transformer, opencascade::handle<IFSelect_Transformer>, Standard_Transient> cls_IFSelect_Transformer(mod, "IFSelect_Transformer", "A Transformer defines the way an InterfaceModel is transformed (without sending it to a file). In order to work, each type of Transformer defines it method Perform, it can be parametred as needed.");

// Fields

// Methods
cls_IFSelect_Transformer.def("Perform", (Standard_Boolean (IFSelect_Transformer::*)(const Interface_Graph &, const opencascade::handle<Interface_Protocol> &, Interface_CheckIterator &, opencascade::handle<Interface_InterfaceModel> &)) &IFSelect_Transformer::Perform, "Performs a Transformation (defined by each sub-class) : <G> gives the input data (especially the starting model) and can be used for queries (by Selections, etc...) <protocol> allows to work with General Services as necessary (it applies to input data) If the change corresponds to a conversion to a new protocol, see also the method ChangeProtocol <checks> stores produced checks messages if any <newmod> gives the result of the transformation : - if it is Null (i.e. has not been affected), the transformation has been made on the spot, it is assumed to cause no change to the graph of dependances - if it equates the starting Model, it has been transformed on the spot (possibiliy some entities were replaced inside it) - if it is new, it corresponds to a new data set which replaces the starting one", py::arg("G"), py::arg("protocol"), py::arg("checks"), py::arg("newmod"));
cls_IFSelect_Transformer.def("ChangeProtocol", (Standard_Boolean (IFSelect_Transformer::*)(opencascade::handle<Interface_Protocol> &) const) &IFSelect_Transformer::ChangeProtocol, "This methods allows to declare that the Protocol applied to the new Model has changed. It applies to the last call to Perform.", py::arg("newproto"));
cls_IFSelect_Transformer.def("Updated", (Standard_Boolean (IFSelect_Transformer::*)(const opencascade::handle<Standard_Transient> &, opencascade::handle<Standard_Transient> &) const) &IFSelect_Transformer::Updated, "This method allows to know what happened to a starting entity after the last Perform. If <entfrom> (from starting model) has one and only one known item which corresponds in the new produced model, this method must return True and fill the argument <entto>. Else, it returns False.", py::arg("entfrom"), py::arg("entto"));
cls_IFSelect_Transformer.def("Label", (TCollection_AsciiString (IFSelect_Transformer::*)() const) &IFSelect_Transformer::Label, "Returns a text which defines the way a Transformer works (to identify the transformation it performs)");
cls_IFSelect_Transformer.def_static("get_type_name_", (const char * (*)()) &IFSelect_Transformer::get_type_name, "None");
cls_IFSelect_Transformer.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_Transformer::get_type_descriptor, "None");
cls_IFSelect_Transformer.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_Transformer::*)() const) &IFSelect_Transformer::DynamicType, "None");

// Enums

}