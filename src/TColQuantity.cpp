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
#include <NCollection_Array1.hxx>
#include <TColQuantity_Array1OfLength.hxx>
#include <NCollection_Array2.hxx>
#include <TColQuantity_Array2OfLength.hxx>
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <NCollection_BaseAllocator.hxx>
#include <Standard_Type.hxx>
#include <TColQuantity_HArray1OfLength.hxx>
#include <TColQuantity_HArray2OfLength.hxx>
#include <NCollection_Templates.hpp>

PYBIND11_MODULE(TColQuantity, mod) {

	// IMPORT
	py::module::import("OCCT.Standard");
	py::module::import("OCCT.NCollection");

	py::module other_mod;

	// IMPORT GUARDS

	// ENUMS

	// FUNCTIONS

	// CLASSES
	// C:\Miniconda\envs\occt\Library\include\opencascade\TColQuantity_Array1OfLength.hxx
	bind_NCollection_Array1<double>(mod, "TColQuantity_Array1OfLength");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColQuantity_Array2OfLength.hxx
	bind_NCollection_Array2<double>(mod, "TColQuantity_Array2OfLength");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColQuantity_HArray1OfLength.hxx
	py::class_<TColQuantity_HArray1OfLength, opencascade::handle<TColQuantity_HArray1OfLength>, TColQuantity_Array1OfLength, Standard_Transient> cls_TColQuantity_HArray1OfLength(mod, "TColQuantity_HArray1OfLength", "None");
	cls_TColQuantity_HArray1OfLength.def(py::init<const Standard_Integer, const Standard_Integer>(), py::arg("theLower"), py::arg("theUpper"));
	cls_TColQuantity_HArray1OfLength.def(py::init<const Standard_Integer, const Standard_Integer, const TColQuantity_Array1OfLength::value_type &>(), py::arg("theLower"), py::arg("theUpper"), py::arg("theValue"));
	cls_TColQuantity_HArray1OfLength.def(py::init<const TColQuantity_Array1OfLength &>(), py::arg("theOther"));
	cls_TColQuantity_HArray1OfLength.def("Array1", (const TColQuantity_Array1OfLength & (TColQuantity_HArray1OfLength::*)() const ) &TColQuantity_HArray1OfLength::Array1, "None");
	cls_TColQuantity_HArray1OfLength.def("ChangeArray1", (TColQuantity_Array1OfLength & (TColQuantity_HArray1OfLength::*)()) &TColQuantity_HArray1OfLength::ChangeArray1, "None");
	cls_TColQuantity_HArray1OfLength.def_static("get_type_name_", (const char * (*)()) &TColQuantity_HArray1OfLength::get_type_name, "None");
	cls_TColQuantity_HArray1OfLength.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColQuantity_HArray1OfLength::get_type_descriptor, "None");
	cls_TColQuantity_HArray1OfLength.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColQuantity_HArray1OfLength::*)() const ) &TColQuantity_HArray1OfLength::DynamicType, "None");

	// C:\Miniconda\envs\occt\Library\include\opencascade\TColQuantity_HArray2OfLength.hxx
	py::class_<TColQuantity_HArray2OfLength, opencascade::handle<TColQuantity_HArray2OfLength>, TColQuantity_Array2OfLength, Standard_Transient> cls_TColQuantity_HArray2OfLength(mod, "TColQuantity_HArray2OfLength", "None");
	cls_TColQuantity_HArray2OfLength.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"));
	cls_TColQuantity_HArray2OfLength.def(py::init<const Standard_Integer, const Standard_Integer, const Standard_Integer, const Standard_Integer, const TColQuantity_Array2OfLength::value_type &>(), py::arg("theRowLow"), py::arg("theRowUpp"), py::arg("theColLow"), py::arg("theColUpp"), py::arg("theValue"));
	cls_TColQuantity_HArray2OfLength.def(py::init<const TColQuantity_Array2OfLength &>(), py::arg("theOther"));
	cls_TColQuantity_HArray2OfLength.def("Array2", (const TColQuantity_Array2OfLength & (TColQuantity_HArray2OfLength::*)() const ) &TColQuantity_HArray2OfLength::Array2, "None");
	cls_TColQuantity_HArray2OfLength.def("ChangeArray2", (TColQuantity_Array2OfLength & (TColQuantity_HArray2OfLength::*)()) &TColQuantity_HArray2OfLength::ChangeArray2, "None");
	cls_TColQuantity_HArray2OfLength.def_static("get_type_name_", (const char * (*)()) &TColQuantity_HArray2OfLength::get_type_name, "None");
	cls_TColQuantity_HArray2OfLength.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &TColQuantity_HArray2OfLength::get_type_descriptor, "None");
	cls_TColQuantity_HArray2OfLength.def("DynamicType", (const opencascade::handle<Standard_Type> & (TColQuantity_HArray2OfLength::*)() const ) &TColQuantity_HArray2OfLength::DynamicType, "None");


}
