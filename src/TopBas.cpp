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
#include <TopAbs_Orientation.hxx>
#include <TopBas_TestInterference.hxx>
#include <NCollection_BaseList.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <NCollection_List.hxx>
#include <TopBas_ListOfTestInterference.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(TopBas, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.TopAbs");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\TopBas_TestInterference.hxx
	py::class_<TopBas_TestInterference, std::unique_ptr<TopBas_TestInterference, Deleter<TopBas_TestInterference>>> cls_TopBas_TestInterference(mod, "TopBas_TestInterference", "None");
	cls_TopBas_TestInterference.def(py::init<>());
	cls_TopBas_TestInterference.def(py::init<const Standard_Real &, const Standard_Integer &, const TopAbs_Orientation, const TopAbs_Orientation, const TopAbs_Orientation>(), py::arg("Inters"), py::arg("Bound"), py::arg("Orient"), py::arg("Trans"), py::arg("BTrans"));
	cls_TopBas_TestInterference.def("Intersection", (void (TopBas_TestInterference::*)(const Standard_Real &)) &TopBas_TestInterference::Intersection, "None", py::arg("I"));
	cls_TopBas_TestInterference.def("Boundary", (void (TopBas_TestInterference::*)(const Standard_Integer &)) &TopBas_TestInterference::Boundary, "None", py::arg("B"));
	cls_TopBas_TestInterference.def("Orientation", (void (TopBas_TestInterference::*)(const TopAbs_Orientation)) &TopBas_TestInterference::Orientation, "None", py::arg("O"));
	cls_TopBas_TestInterference.def("Transition", (void (TopBas_TestInterference::*)(const TopAbs_Orientation)) &TopBas_TestInterference::Transition, "None", py::arg("Tr"));
	cls_TopBas_TestInterference.def("BoundaryTransition", (void (TopBas_TestInterference::*)(const TopAbs_Orientation)) &TopBas_TestInterference::BoundaryTransition, "None", py::arg("BTr"));
	cls_TopBas_TestInterference.def("Intersection", (const Standard_Real & (TopBas_TestInterference::*)() const ) &TopBas_TestInterference::Intersection, "None");
	cls_TopBas_TestInterference.def("ChangeIntersection", (Standard_Real & (TopBas_TestInterference::*)()) &TopBas_TestInterference::ChangeIntersection, "None");
	cls_TopBas_TestInterference.def("Boundary", (const Standard_Integer & (TopBas_TestInterference::*)() const ) &TopBas_TestInterference::Boundary, "None");
	cls_TopBas_TestInterference.def("ChangeBoundary", (Standard_Integer & (TopBas_TestInterference::*)()) &TopBas_TestInterference::ChangeBoundary, "None");
	cls_TopBas_TestInterference.def("Orientation", (TopAbs_Orientation (TopBas_TestInterference::*)() const ) &TopBas_TestInterference::Orientation, "None");
	cls_TopBas_TestInterference.def("Transition", (TopAbs_Orientation (TopBas_TestInterference::*)() const ) &TopBas_TestInterference::Transition, "None");
	cls_TopBas_TestInterference.def("BoundaryTransition", (TopAbs_Orientation (TopBas_TestInterference::*)() const ) &TopBas_TestInterference::BoundaryTransition, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopBas_ListOfTestInterference.hxx
	bind_NCollection_List<TopBas_TestInterference>(mod, "TopBas_ListOfTestInterference");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TopBas_ListOfTestInterference.hxx
	bind_NCollection_TListIterator<TopBas_TestInterference>(mod, "TopBas_ListIteratorOfListOfTestInterference");


}
