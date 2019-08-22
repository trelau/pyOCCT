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
#include <BOPAlgo_Options.hxx>
#include <Standard.hxx>
#include <TopoDS_Shape.hxx>
#include <Standard_TypeDef.hxx>
#include <BOPAlgo_Operation.hxx>
#include <BOPAlgo_ListOfCheckResult.hxx>
#include <BRepAlgoAPI_Check.hxx>

void bind_BRepAlgoAPI_Check(py::module &mod){

py::class_<BRepAlgoAPI_Check, BOPAlgo_Options> cls_BRepAlgoAPI_Check(mod, "BRepAlgoAPI_Check", "The class Check provides a diagnostic tool for checking the validity of the single shape or couple of shapes. The shapes are checked on: - Topological validity; - Small edges; - Self-interference; - Validity for Boolean operation of certain type (for couple of shapes only).");

// Constructors
cls_BRepAlgoAPI_Check.def(py::init<>());
cls_BRepAlgoAPI_Check.def(py::init<const TopoDS_Shape &>(), py::arg("theS"));
cls_BRepAlgoAPI_Check.def(py::init<const TopoDS_Shape &, const Standard_Boolean>(), py::arg("theS"), py::arg("bTestSE"));
cls_BRepAlgoAPI_Check.def(py::init<const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean>(), py::arg("theS"), py::arg("bTestSE"), py::arg("bTestSI"));
cls_BRepAlgoAPI_Check.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &>(), py::arg("theS1"), py::arg("theS2"));
cls_BRepAlgoAPI_Check.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const BOPAlgo_Operation>(), py::arg("theS1"), py::arg("theS2"), py::arg("theOp"));
cls_BRepAlgoAPI_Check.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const BOPAlgo_Operation, const Standard_Boolean>(), py::arg("theS1"), py::arg("theS2"), py::arg("theOp"), py::arg("bTestSE"));
cls_BRepAlgoAPI_Check.def(py::init<const TopoDS_Shape &, const TopoDS_Shape &, const BOPAlgo_Operation, const Standard_Boolean, const Standard_Boolean>(), py::arg("theS1"), py::arg("theS2"), py::arg("theOp"), py::arg("bTestSE"), py::arg("bTestSI"));

// Fields

// Methods
// cls_BRepAlgoAPI_Check.def_static("operator new_", (void * (*)(size_t)) &BRepAlgoAPI_Check::operator new, "None", py::arg("theSize"));
// cls_BRepAlgoAPI_Check.def_static("operator delete_", (void (*)(void *)) &BRepAlgoAPI_Check::operator delete, "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_Check.def_static("operator new[]_", (void * (*)(size_t)) &BRepAlgoAPI_Check::operator new[], "None", py::arg("theSize"));
// cls_BRepAlgoAPI_Check.def_static("operator delete[]_", (void (*)(void *)) &BRepAlgoAPI_Check::operator delete[], "None", py::arg("theAddress"));
// cls_BRepAlgoAPI_Check.def_static("operator new_", (void * (*)(size_t, void *)) &BRepAlgoAPI_Check::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepAlgoAPI_Check.def_static("operator delete_", (void (*)(void *, void *)) &BRepAlgoAPI_Check::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepAlgoAPI_Check.def("SetData", [](BRepAlgoAPI_Check &self, const TopoDS_Shape & a0) -> void { return self.SetData(a0); });
cls_BRepAlgoAPI_Check.def("SetData", [](BRepAlgoAPI_Check &self, const TopoDS_Shape & a0, const Standard_Boolean a1) -> void { return self.SetData(a0, a1); });
cls_BRepAlgoAPI_Check.def("SetData", (void (BRepAlgoAPI_Check::*)(const TopoDS_Shape &, const Standard_Boolean, const Standard_Boolean)) &BRepAlgoAPI_Check::SetData, "Initializes the algorithm with single shape.", py::arg("theS"), py::arg("bTestSE"), py::arg("bTestSI"));
cls_BRepAlgoAPI_Check.def("SetData", [](BRepAlgoAPI_Check &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1) -> void { return self.SetData(a0, a1); });
cls_BRepAlgoAPI_Check.def("SetData", [](BRepAlgoAPI_Check &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1, const BOPAlgo_Operation a2) -> void { return self.SetData(a0, a1, a2); });
cls_BRepAlgoAPI_Check.def("SetData", [](BRepAlgoAPI_Check &self, const TopoDS_Shape & a0, const TopoDS_Shape & a1, const BOPAlgo_Operation a2, const Standard_Boolean a3) -> void { return self.SetData(a0, a1, a2, a3); });
cls_BRepAlgoAPI_Check.def("SetData", (void (BRepAlgoAPI_Check::*)(const TopoDS_Shape &, const TopoDS_Shape &, const BOPAlgo_Operation, const Standard_Boolean, const Standard_Boolean)) &BRepAlgoAPI_Check::SetData, "Initializes the algorithm with couple of shapes. Additionally to the validity checks of each given shape, the types of the given shapes will be checked on validity for Boolean operation of given type.", py::arg("theS1"), py::arg("theS2"), py::arg("theOp"), py::arg("bTestSE"), py::arg("bTestSI"));
cls_BRepAlgoAPI_Check.def("Perform", (void (BRepAlgoAPI_Check::*)()) &BRepAlgoAPI_Check::Perform, "Performs the check.");
cls_BRepAlgoAPI_Check.def("IsValid", (Standard_Boolean (BRepAlgoAPI_Check::*)()) &BRepAlgoAPI_Check::IsValid, "Shows whether shape(s) valid or not.");
cls_BRepAlgoAPI_Check.def("Result", (const BOPAlgo_ListOfCheckResult & (BRepAlgoAPI_Check::*)()) &BRepAlgoAPI_Check::Result, "Returns faulty shapes.");

// Enums

}