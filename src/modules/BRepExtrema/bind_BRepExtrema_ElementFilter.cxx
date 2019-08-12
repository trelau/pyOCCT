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
#include <BRepExtrema_ElementFilter.hxx>
#include <Standard_TypeDef.hxx>

void bind_BRepExtrema_ElementFilter(py::module &mod){

py::class_<BRepExtrema_ElementFilter, std::unique_ptr<BRepExtrema_ElementFilter, Deleter<BRepExtrema_ElementFilter>>> cls_BRepExtrema_ElementFilter(mod, "BRepExtrema_ElementFilter", "Filtering tool used to detect if two given mesh elements should be tested for overlapping/intersection or not.");

// Constructors

// Fields

// Methods
cls_BRepExtrema_ElementFilter.def("PreCheckElements", (BRepExtrema_ElementFilter::FilterResult (BRepExtrema_ElementFilter::*)(const Standard_Integer, const Standard_Integer)) &BRepExtrema_ElementFilter::PreCheckElements, "Checks if two mesh elements should be tested for overlapping/intersection (used for detection correct/incorrect cases of shared edges and vertices).", py::arg(""), py::arg(""));

// Enums
py::enum_<BRepExtrema_ElementFilter::FilterResult>(cls_BRepExtrema_ElementFilter, "FilterResult", "Result of filtering function.")
	.value("NoCheck", BRepExtrema_ElementFilter::FilterResult::NoCheck)
	.value("Overlap", BRepExtrema_ElementFilter::FilterResult::Overlap)
	.value("DoCheck", BRepExtrema_ElementFilter::FilterResult::DoCheck)
	.export_values();

}