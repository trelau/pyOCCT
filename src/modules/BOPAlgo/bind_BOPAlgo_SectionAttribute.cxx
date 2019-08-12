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
#include <Standard_TypeDef.hxx>
#include <BOPAlgo_SectionAttribute.hxx>

void bind_BOPAlgo_SectionAttribute(py::module &mod){

py::class_<BOPAlgo_SectionAttribute, std::unique_ptr<BOPAlgo_SectionAttribute, Deleter<BOPAlgo_SectionAttribute>>> cls_BOPAlgo_SectionAttribute(mod, "BOPAlgo_SectionAttribute", "Class is a container of the flags used by intersection algorithm");

// Constructors
cls_BOPAlgo_SectionAttribute.def(py::init<>());
cls_BOPAlgo_SectionAttribute.def(py::init<const Standard_Boolean, const Standard_Boolean, const Standard_Boolean>(), py::arg("theAproximation"), py::arg("thePCurveOnS1"), py::arg("thePCurveOnS2"));

// Fields

// Methods
cls_BOPAlgo_SectionAttribute.def("Approximation", (void (BOPAlgo_SectionAttribute::*)(const Standard_Boolean)) &BOPAlgo_SectionAttribute::Approximation, "Sets the Approximation flag", py::arg("theApprox"));
cls_BOPAlgo_SectionAttribute.def("PCurveOnS1", (void (BOPAlgo_SectionAttribute::*)(const Standard_Boolean)) &BOPAlgo_SectionAttribute::PCurveOnS1, "Sets the PCurveOnS1 flag", py::arg("thePCurveOnS1"));
cls_BOPAlgo_SectionAttribute.def("PCurveOnS2", (void (BOPAlgo_SectionAttribute::*)(const Standard_Boolean)) &BOPAlgo_SectionAttribute::PCurveOnS2, "Sets the PCurveOnS2 flag", py::arg("thePCurveOnS2"));
cls_BOPAlgo_SectionAttribute.def("Approximation", (Standard_Boolean (BOPAlgo_SectionAttribute::*)() const) &BOPAlgo_SectionAttribute::Approximation, "Returns the Approximation flag");
cls_BOPAlgo_SectionAttribute.def("PCurveOnS1", (Standard_Boolean (BOPAlgo_SectionAttribute::*)() const) &BOPAlgo_SectionAttribute::PCurveOnS1, "Returns the PCurveOnS1 flag");
cls_BOPAlgo_SectionAttribute.def("PCurveOnS2", (Standard_Boolean (BOPAlgo_SectionAttribute::*)() const) &BOPAlgo_SectionAttribute::PCurveOnS2, "Returns the PCurveOnS2 flag");

// Enums

}