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
#include <IFSelect_PrintCount.hxx>

void bind_IFSelect_PrintCount(py::module &mod){

py::enum_<IFSelect_PrintCount>(mod, "IFSelect_PrintCount", "Lets you choose the manner in which you want to analyze an IGES or STEP file. Your analysis can be either message-oriented or entity-oriented. The specific values are as follows: - ItemsByEntity is a sequential list of all messages per entity of the defined type - CountByItem is the number of entities of the defined type, with their rank number per message - ShortByItem is the number of entities of the defined type, with their types per message; displays the rank numbers of the first five entities of the defined type per message - ListByItem is the number of entities of the defined type per message and the numbers of the entities - EntitiesByItem is the number of entities of the defined type, with their types, rank numbers and Directory Entry numbers per message - GeneralInfo is general information on transfer such as: - number of entities - number of roots - number of resulting Open CASCADE shapes - number of warnings and failures - CountSummary summary statistics for counters and signatures - ResultCount information that contains the number of roots in the IGES file and the number of resulting Open CASCADE shapes. - Mapping of the IGES root entities to the resulting Open CASCADE shape (including type and form of the IGES entity and type of the resulting shape).")
	.value("IFSelect_ItemsByEntity", IFSelect_PrintCount::IFSelect_ItemsByEntity)
	.value("IFSelect_CountByItem", IFSelect_PrintCount::IFSelect_CountByItem)
	.value("IFSelect_ShortByItem", IFSelect_PrintCount::IFSelect_ShortByItem)
	.value("IFSelect_ListByItem", IFSelect_PrintCount::IFSelect_ListByItem)
	.value("IFSelect_EntitiesByItem", IFSelect_PrintCount::IFSelect_EntitiesByItem)
	.value("IFSelect_CountSummary", IFSelect_PrintCount::IFSelect_CountSummary)
	.value("IFSelect_GeneralInfo", IFSelect_PrintCount::IFSelect_GeneralInfo)
	.value("IFSelect_Mapping", IFSelect_PrintCount::IFSelect_Mapping)
	.value("IFSelect_ResultCount", IFSelect_PrintCount::IFSelect_ResultCount)
	.export_values();


}