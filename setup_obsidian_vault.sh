#!/bin/bash

# Obsidian Vault Setup Script for Learning Multiple Domains
# Creates a comprehensive vault structure for Data Engineering, Competitive Programming,
# University Studies, and Book Reading

# Set the vault directory - replace with your desired path
VAULT_DIR="$HOME/ObsidianVault"

# Create the vault directory if it doesn't exist
mkdir -p "$VAULT_DIR"
cd "$VAULT_DIR"

# Function to create directories and files
create_structure() {
    local dir="$1"
    shift
    mkdir -p "$dir"
    
    for item in "$@"; do
        if [[ "$item" == *".md" ]]; then
            touch "$dir/$item"
        else
            mkdir -p "$dir/$item"
        fi
    done
}

# Function to write content to files
write_to_file() {
    local file="$1"
    local content="$2"
    echo -e "$content" > "$file"
}

echo "Creating main directory structure..."

# Create core structure
create_structure "$VAULT_DIR" \
    "Data Engineering" \
    "Competitive Programming" \
    "University" \
    "Books" \
    "Daily Notes" \
    "Projects" \
    "MOC" \
    "Templates" \
    "Attachments" \
    "Fleeting Notes" \
    "Permanent Notes" \
    "Reviews" \
    "Dashboards" \
    ".obsidian"

# Data Engineering Structure
create_structure "$VAULT_DIR/Data Engineering" \
    "Concepts" \
    "Projects" \
    "Resources" \
    "Tools" \
    "Workflows" \
    "Interview Prep" \
    "Certifications" \
    "MOC-DataEngineering.md" \
    "Glossary.md" \
    "Learning Path.md"

# Concepts subfolders for Data Engineering
create_structure "$VAULT_DIR/Data Engineering/Concepts" \
    "Databases" \
    "ETL-ELT" \
    "Big Data" \
    "Data Modeling" \
    "Data Warehousing" \
    "Stream Processing" \
    "Cloud Solutions"

# Tools subfolders for Data Engineering
create_structure "$VAULT_DIR/Data Engineering/Tools" \
    "Spark" \
    "Hadoop" \
    "Airflow" \
    "Kafka" \
    "SQL" \
    "NoSQL" \
    "AWS" \
    "GCP" \
    "Azure"

# Competitive Programming Structure
create_structure "$VAULT_DIR/Competitive Programming" \
    "Algorithms" \
    "Data Structures" \
    "Problem Solutions" \
    "Techniques" \
    "Contest Notes" \
    "Practice Log" \
    "Templates" \
    "Resources" \
    "MOC-CompetitiveProgramming.md" \
    "Problem Patterns.md"

# Algorithm categories
create_structure "$VAULT_DIR/Competitive Programming/Algorithms" \
    "Sorting" \
    "Searching" \
    "Graph" \
    "Dynamic Programming" \
    "Greedy" \
    "String" \
    "Math" \
    "Bit Manipulation"

# Data Structures categories
create_structure "$VAULT_DIR/Competitive Programming/Data Structures" \
    "Arrays" \
    "Linked Lists" \
    "Stacks and Queues" \
    "Trees" \
    "Heaps" \
    "Hash Tables" \
    "Graphs" \
    "Advanced"

# Problem Solutions by platform
create_structure "$VAULT_DIR/Competitive Programming/Problem Solutions" \
    "LeetCode" \
    "Codeforces" \
    "HackerRank" \
    "CodeChef" \
    "AtCoder" \
    "Project Euler" \
    "By Difficulty"

# University Structure
create_structure "$VAULT_DIR/University" \
    "Courses" \
    "Labs" \
    "Group Projects" \
    "Academic Calendar" \
    "Grade Tracker" \
    "MOC-University.md" \
    "Degree Requirements.md" \
    "Study Groups.md"

# Example course structure - repeat for each course
create_structure "$VAULT_DIR/University/Courses/CS101" \
    "Lectures" \
    "Assignments" \
    "Exam Prep" \
    "Resources" \
    "Notes" \
    "CS101-Summary.md"

# Books Structure
create_structure "$VAULT_DIR/Books" \
    "Book Notes" \
    "Reading Lists" \
    "Summaries" \
    "Quotes" \
    "Book Reviews" \
    "Book Database.md" \
    "MOC-Books.md" \
    "Reading Stats.md"

# Template Structure
create_structure "$VAULT_DIR/Templates" \
    "Daily Note.md" \
    "Book Note.md" \
    "Course Note.md" \
    "Lecture Note.md" \
    "Algorithm Note.md" \
    "Project Note.md" \
    "Problem Solution.md" \
    "Concept Note.md" \
    "Meeting Note.md"

# Dashboard Structure
create_structure "$VAULT_DIR/Dashboards" \
    "Main Dashboard.md" \
    "Learning Progress.md" \
    "Reading Dashboard.md" \
    "University Dashboard.md" \
    "Project Status.md"

# Write content to template files
write_to_file "$VAULT_DIR/Templates/Daily Note.md" "# Daily Note - {{date:YYYY-MM-DD}}\n\n## Tasks\n- [ ] \n\n## Data Engineering\n\n## Competitive Programming\n\n## University\n\n## Reading\n\n## Thoughts & Ideas\n\n## Links\n"

write_to_file "$VAULT_DIR/Templates/Book Note.md" "# {{title}}\n\nAuthor: \nCategory: #book \nStarted: {{date:YYYY-MM-DD}}\nCompleted: \nRating: /5\n\n## Summary\n\n## Key Insights\n\n## Quotes\n\n## Action Items\n\n## Links\n"

write_to_file "$VAULT_DIR/Templates/Problem Solution.md" "# Problem: {{title}}\n\nSource: \nDifficulty: \nTags: \n\n## Problem Statement\n\n## Understanding\n\n## Approach\n\n## Code\n\n```\n\n```\n\n## Complexity Analysis\n- Time Complexity: \n- Space Complexity: \n\n## Learnings\n\n## Related Problems\n"

# Write content to MOC files
write_to_file "$VAULT_DIR/MOC/MOC-Home.md" "# Home\n\n## Areas\n- [[MOC-DataEngineering]]\n- [[MOC-CompetitiveProgramming]]\n- [[MOC-University]]\n- [[MOC-Books]]\n\n## Current Projects\n\n## Quick Links\n- [[Main Dashboard]]\n- [[Today's Note]]\n\n## Recent Notes\n<!-- This will use Dataview plugin once installed -->\n"

write_to_file "$VAULT_DIR/Dashboards/Main Dashboard.md" "# Main Dashboard\n\n## Current Focus\n- Data Engineering: \n- Competitive Programming: \n- University: \n- Books: \n\n## Tasks Due Soon\n<!-- This will use Tasks plugin once installed -->\n\n## Recent Activity\n<!-- This will use Dataview plugin once installed -->\n\n## Learning Statistics\n<!-- This will use Dataview plugin once installed -->\n\n## Quick Links\n- [[MOC-DataEngineering]]\n- [[MOC-CompetitiveProgramming]]\n- [[MOC-University]]\n- [[MOC-Books]]\n"

write_to_file "$VAULT_DIR/Data Engineering/MOC-DataEngineering.md" "# Data Engineering\n\n## Learning Path\n- [[Learning Path]]\n\n## Concepts\n- [[Databases]]\n- [[ETL-ELT]]\n- [[Big Data]]\n- [[Data Modeling]]\n- [[Data Warehousing]]\n\n## Current Projects\n\n## Resources\n\n## Study Log\n"

write_to_file "$VAULT_DIR/Competitive Programming/MOC-CompetitiveProgramming.md" "# Competitive Programming\n\n## Algorithm Categories\n- [[Sorting]]\n- [[Searching]]\n- [[Graph]]\n- [[Dynamic Programming]]\n- [[Greedy]]\n\n## Data Structures\n- [[Arrays]]\n- [[Linked Lists]]\n- [[Trees]]\n- [[Graphs]]\n\n## Problem Solutions\n- [[LeetCode]]\n- [[Codeforces]]\n\n## Practice Log\n"

write_to_file "$VAULT_DIR/University/MOC-University.md" "# University Studies\n\n## Current Courses\n- [[CS101]]\n\n## Important Dates\n\n## Grades\n\n## Projects\n\n## Resources\n"

write_to_file "$VAULT_DIR/Books/MOC-Books.md" "# Books\n\n## Currently Reading\n\n## Want to Read\n\n## Completed\n\n## By Category\n\n## Notes\n"

write_to_file "$VAULT_DIR/Books/Book Database.md" "# Book Database\n\n| Title | Author | Category | Status | Started | Completed | Rating | Notes |\n|-------|--------|----------|--------|---------|-----------|--------|---------|\n|       |        |          |        |         |           |        | [[]] |\n"

# Create configuration file for recommended plugins
write_to_file "$VAULT_DIR/recommended_plugins.md" "# Recommended Plugins for this Vault Structure\n\n1. **Dataview** - For creating dynamic views of your notes\n2. **Calendar** - For managing daily notes\n3. **Templater** - For enhanced templates\n4. **Tasks** - For tracking tasks across notes\n5. **Kanban** - For visual project management\n6. **Spaced Repetition** - For review of key concepts\n7. **Mind Map** - For visual organization of concepts\n8. **Advanced Tables** - For better table management\n9. **Obsidian Git** - For backing up your vault\n10. **Citations** - For academic paper references\n11. **Excalidraw** - For diagrams and visual notes\n12. **Sliding Panes** - For better navigation\n"

echo "Creating .gitignore for version control..."
write_to_file "$VAULT_DIR/.gitignore" ".obsidian/cache\n.obsidian/workspace\n.trash/\n.DS_Store\nAttachments/\n"

echo "Creating a README file for your vault..."
write_to_file "$VAULT_DIR/README.md" "# My Learning Obsidian Vault\n\nThis vault is structured to support learning in multiple domains:\n- Data Engineering\n- Competitive Programming\n- University Studies\n- Book Reading\n\nSee [[MOC-Home]] for navigation and [[recommended_plugins]] for setup recommendations.\n"

echo "Done! Your Obsidian vault structure has been created at $VAULT_DIR"
echo "Next steps:"
echo "1. Open this folder as a vault in Obsidian"
echo "2. Install recommended plugins from recommended_plugins.md"
echo "3. Configure daily notes plugin to use the Daily Note template"
echo "4. Set up Dataview queries in dashboard files"
